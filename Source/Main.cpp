#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "Registrador.hpp"
#include "Station.hpp"
#include "Log.hpp"

using namespace std;

// === CONFIGURACAO DE ARQUIVOS DE ENTRADA E SAIDA ===
const std::string CAMINHO_ENTRADA = "../Input/Input_1.txt"; // Altere aqui para testar outros arquivos
const std::string CAMINHO_SAIDA = "../Output/output.md";

vector<string> lerInstrucoes(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    vector<string> instrucoes;
    string linha;
    
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo: " << caminhoArquivo << endl;
        exit(1);
    }
    
    while (getline(arquivo, linha) && instrucoes.size() < 100) {
        if (!linha.empty()) {
            instrucoes.push_back(linha);
        }
    }
    return instrucoes;
}

// Vetor de memoria global
vector<int> memoria(1024, 0); // Memoria simulada

// Funcao para imprimir memoria (para o log)
void imprimirMemoria(Log& logger) {
    cout << "\nMemoria (primeiras 8 posicoes): ";
    for (int i = 0; i < 8; ++i) {
        cout << "[" << i << "]=" << memoria[i] << " ";
    }
    cout << endl;
}

int main() {
    // Ler instrucoes
    auto stringsInstrucoes = lerInstrucoes(CAMINHO_ENTRADA);
    vector<Instruction> instrucoes;
    for (const auto& str : stringsInstrucoes) {
        instrucoes.push_back(Instruction::parseInstruction(str));
    }
    
    // Inicializar registradores com valores diferentes de zero
    vector<Registrador> registradores(32);
    for (int i = 0; i < 32; ++i) {
        registradores[i].setValue(i * 10); // Exemplo: R0=0, R1=10, R2=20...
    }
    ReservationStations estacoes;
    Log logger(CAMINHO_SAIDA);
    
    int ciclo = 1;
    size_t instrucaoAtual = 0;
    bool simulacaoFinalizada = false;
    
    while (!simulacaoFinalizada && ciclo < 1000) {
        logger.newCycle(ciclo);
        
        // Fase de despacho
        if (instrucaoAtual < instrucoes.size()) {
            int indiceEstacao = estacoes.dispatchInstruction(instrucoes[instrucaoAtual], ciclo, instrucaoAtual);
            if (indiceEstacao != -1) {
                logger.logInstructionStep(Log::InstructionStep::Dispatched, instrucaoAtual + 1);
                instrucaoAtual++;
            } else {
                logger.logStationDependency(instrucaoAtual + 1);
            }
        }
        
        // Fase de execucao
        bool algumaEstacaoOcupada = false;
        for (size_t i = 0; i < estacoes.size(); i++) {
            Station& estacao = estacoes[i];
            if (!estacao.isBusy()) continue;
            
            Instruction instrucao = estacao.getInstruction();
            int linhaDebug = estacao.getDebugInstructionLine() + 1;
            
            // Pular se acabou de despachar neste ciclo
            if (instrucao.getIssuedAt() == ciclo) continue;
            
            // Dependencias falsas (WAW/WAR):
            // WAW: nao iniciar se houver outra instrucao futura que escrevera no mesmo registrador destino
            // WAR: nao iniciar se o destino desta for lido por outra instrucao ainda nao finalizada
            bool temWAW = false, temWAR = false;
            for (size_t j = 0; j < estacoes.size(); ++j) {
                if (i == j) continue;
                const Station& outra = estacoes[j];
                if (!outra.isBusy()) continue;
                const Instruction& outraInstrucao = outra.getInstruction();
                // WAW: mesmo destino, outra instrucao ainda nao escrita
                if (outraInstrucao.getTargetReg() == instrucao.getTargetReg() && outraInstrucao.getWrittenAt() == -1) {
                    temWAW = true;
                }
                // WAR: destino desta e fonte de outra ainda nao finalizada
                if ((outraInstrucao.getSrcReg1() == instrucao.getTargetReg() ||
                     (outraInstrucao.getType() == InstructionType::ThreeReg && outraInstrucao.getSrcReg2() == instrucao.getTargetReg()))
                    && outraInstrucao.getFinishedAt() == -1) {
                    temWAR = true;
                }
            }
            if (temWAW || temWAR) {
                // Nao inicia execucao
                continue;
            }
            // Iniciar execucao se ainda nao iniciou
            if (instrucao.getStartedAt() == -1) {
                vector<int> regsAssociados = instrucao.getAssociatedRegisters();
                bool podeIniciar = true;
                // Checar registradores fonte
                for (int j = 1; j < regsAssociados.size(); j++) {
                    int indiceReg = regsAssociados[j];
                    if (indiceReg < 0) continue;
                    if (!registradores[indiceReg].isFree(i)) {
                        logger.logRegisterDependency(indiceReg, linhaDebug);
                        podeIniciar = false;
                        break;
                    }
                }
                if (podeIniciar) {
                    registradores[instrucao.getTargetReg()].setBusyBy(i);
                    logger.logInstructionStep(Log::InstructionStep::Started, linhaDebug);
                    instrucao.setStartedAt(ciclo);
                    estacao.setInstruction(instrucao);
                }
            }
            // Completar execucao se iniciada
            if (instrucao.getStartedAt() != -1 && instrucao.getFinishedAt() == -1) {
                if (ciclo - instrucao.getStartedAt() >= instrucao.getOperationTime()) {
                    logger.logInstructionStep(Log::InstructionStep::Completed, linhaDebug);
                    instrucao.setFinishedAt(ciclo);
                    instrucao.setWrittenAt(ciclo + 1);
                    estacao.setInstruction(instrucao);
                }
            }
            // Escrever resultado
            if (instrucao.getWrittenAt() == ciclo) {
                int resultado = 0;
                switch (instrucao.getOperation()) {
                    case Operation::ADD:
                        resultado = registradores[instrucao.getSrcReg1()].getValue() + 
                                 registradores[instrucao.getSrcReg2()].getValue();
                        break;
                    case Operation::SUB:
                        resultado = registradores[instrucao.getSrcReg1()].getValue() - 
                                 registradores[instrucao.getSrcReg2()].getValue();
                        break;
                    case Operation::MUL:
                        resultado = registradores[instrucao.getSrcReg1()].getValue() * 
                                 registradores[instrucao.getSrcReg2()].getValue();
                        break;
                    case Operation::DIV:
                        if (registradores[instrucao.getSrcReg2()].getValue() == 0) {
                            resultado = registradores[instrucao.getSrcReg1()].getValue();
                        } else {
                            resultado = registradores[instrucao.getSrcReg1()].getValue() / 
                                     registradores[instrucao.getSrcReg2()].getValue();
                        }
                        break;
                    case Operation::LW: {
                        int endereco = registradores[instrucao.getSrcReg1()].getValue() + instrucao.getOffset();
                        if (endereco >= 0 && endereco < (int)memoria.size())
                            resultado = memoria[endereco];
                        else
                            resultado = 0;
                        break;
                    }
                    case Operation::SW: {
                        int endereco = registradores[instrucao.getSrcReg1()].getValue() + instrucao.getOffset();
                        if (endereco >= 0 && endereco < (int)memoria.size())
                            memoria[endereco] = registradores[instrucao.getTargetReg()].getValue();
                        break;
                    }
                }
                if (instrucao.getOperation() != Operation::SW)
                    registradores[instrucao.getTargetReg()].setValue(resultado);
                logger.logInstructionStep(Log::InstructionStep::WroteToMemory, linhaDebug);
                estacao.setBusy(false);
                registradores[instrucao.getTargetReg()].release();
            }
            if (estacao.isBusy()) algumaEstacaoOcupada = true;
        }
        // Logar estado
        logger.logRegisters(registradores, estacoes);
        logger.logStations(estacoes);
        logger.logMemory(memoria, 8); // Loga as 8 primeiras posicoes da memoria
        imprimirMemoria(logger);
        // Checar termino
        simulacaoFinalizada = (instrucaoAtual >= instrucoes.size()) && !algumaEstacaoOcupada;
        ciclo++;
    }
    cout << "Simulacao finalizada em " << (ciclo - 1) << " ciclos." << endl;
    return 0;
}