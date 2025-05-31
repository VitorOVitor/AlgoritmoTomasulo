# AlgoritmoTomasulo
Repositório para o projeto de criação de uma simulação do algoritmo de Tomasulo, da disciplina de Arquitetura de Computadores III da PUC Minas

# Simulador do Algoritmo de Tomasulo

Este projeto é um simulador educacional do Algoritmo de Tomasulo, implementado em C++. Ele permite visualizar, ciclo a ciclo, a execução de instruções com detecção de dependências (RAW, WAR, WAW), uso de estacoes de reserva, registradores e memoria, sem renomeacao de registradores.

## Como usar

1. **Pre-requisitos:**
   - Compilador C++ (g++, clang++, MSVC, etc.)
   - Visual Studio Code (recomendado)

2. **Compilacao:**
   - O projeto ja esta configurado para compilar todos os arquivos `.cpp` automaticamente ao usar o botao "Run Code" do VSCode.
   - Se preferir, compile manualmente:
     ```sh
     g++ Source/*.cpp -o Source/Main.exe
     ```

3. **Entrada:**
   - Os arquivos de entrada estao na pasta `Input/` (ex: `Input_1.txt`).
   - Para trocar o arquivo de entrada, edite a constante `CAMINHO_ENTRADA` no inicio do `Main.cpp`.

4. **Execucao:**
   - Execute o programa pelo VSCode (botao "Run Code") ou pelo terminal:
     ```sh
     .\Source\Main.exe
     ```
   - O resultado sera salvo em `Output/output.md` e tambem exibido no terminal.

## Saida
- O arquivo `output.md` mostra, ciclo a ciclo:
  - Estado dos registradores
  - Estado das estacoes de reserva
  - Estado das primeiras posicoes da memoria
  - Log das acoes de cada instrucao
- Todos os titulos e secoes estao em portugues sem acentuacao.

## Personalizacao
- Para alterar o numero de posicoes de memoria exibidas, edite a chamada de `logMemory` em `Main.cpp`.
- Para adicionar ou modificar instrucoes, edite os arquivos em `Input/`.

## Observacoes
- O simulador nao faz renomeacao de registradores (Tomasulo classico).
- O codigo esta comentado e modularizado para facilitar o estudo e modificacoes.
- Dependencias de dados (RAW, WAR, WAW) sao tratadas corretamente.




