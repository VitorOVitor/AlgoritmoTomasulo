#include "Log.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Log::Log(const string& path) : logPath(path) {
    setLogPath(path);
}

Log::~Log() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Log::setLogPath(const string& path) {
    logPath = path;
    if (logFile.is_open()) {
        logFile.close();
    }
    logFile.open(logPath, ios::app);
    if (!logFile.is_open()) {
        cerr << "[LogError] Failed to open log file: " << logPath << endl;
    }
}

void Log::newCycle(int ciclo) {
    if (logFile.is_open()) {
        logFile << "# CICLO " << ciclo << "\n";
        logFile << "## Log\n";
    }
}

void Log::logInstructionStep(InstructionStep step, int line) {
    if (!logFile.is_open()) return;
    
    cout << "* \033[32m[" << line << "]\033[0m ";
    logFile << "* [" << line << "] ";
    
    switch (step) {
        case InstructionStep::Dispatched:
            cout << "Dispatched\n";
            logFile << "Dispatched\n";
            break;
        case InstructionStep::Started:
            cout << "Started\n";
            logFile << "Started\n";
            break;
        case InstructionStep::Completed:
            cout << "Completed\n";
            logFile << "Completed\n";
            break;
        case InstructionStep::WroteToMemory:
            cout << "Wrote to memory\n";
            logFile << "Wrote to memory\n";
            break;
        default:
            cout << "Unknown step\n";
            logFile << "Unknown step\n";
    }
}

void Log::logRegisterDependency(int dependency, int line) {
    if (!logFile.is_open()) return;
    
    cout << "* \033[32m[" << line << "]\033[31m Cannot start\033[0m - Waiting for register R" << dependency << "\n";
    logFile << "* [" << line << "] Cannot start, it's waiting for Register R" << dependency << "\n";
}

void Log::logStationDependency(int line) {
    if (!logFile.is_open()) return;
    
    cout << "* \033[32m[" << line << "]\033[31m Cannot be dispatched\033[0m - Waiting for a station to be free\n";
    logFile << "* [" << line << "] Cannot be dispatched, waiting for a station to be free\n";
}

string Log::getOperationName(Operation op) {
    switch(op) {
        case Operation::LW: return "LW";
        case Operation::SW: return "SW";
        case Operation::ADD: return "ADD";
        case Operation::SUB: return "SUB";
        case Operation::MUL: return "MUL";
        case Operation::DIV: return "DIV";
        default: return "UNKNOWN";
    }
}

void Log::logRegisters(const std::vector<Registrador>& registers, const ReservationStations& stations) {
    if (!logFile.is_open()) return;
    logFile << "## Registradores\n```json\n[\n";
    cout << "\n";
    
    for (int i = 0; i < REG_AMOUNT; i++) {
        const Registrador& reg = registers[i];
        
        // Terminal output
        if (i % 4 != 3) {
            if (reg.isFree()) {
                cout << "\x1b[33m[R" << setfill('0') << setw(2) << i << "]: \x1b[32mfree\x1b[0m    ";
            } else {
                cout << "\x1b[33m[R" << setfill('0') << setw(2) << i << "]: \x1b[31mbusy\x1b[0m    ";
            }
        } else {
            if (reg.isFree()) {
                cout << "\x1b[33m[R" << setfill('0') << setw(2) << i << "]: \x1b[32mfree\x1b[0m   \n";
            } else {
                cout << "\x1b[33m[R" << setfill('0') << setw(2) << i << "]: \x1b[31mbusy\x1b[0m   \n";
            }
        }
        
        // File output (JSON)
        if (!reg.isFree()) {
            int stationIndex = reg.getBusyBy();
            int instructionLine = stations[stationIndex].getDebugInstructionLine();
            logFile << "    {\"id\": " << i 
                   << ", \"busyByStation\": " << stationIndex
                   << ", \"busyByInst\": " << instructionLine
                   << ", \"v\": " << reg.getValue() << "},\n";
        }
    }
    logFile << "]\n```\n";  // Corrigido
}

void Log::logStations(const ReservationStations& stations) {
    if (!logFile.is_open()) return;
    logFile << "## Estacoes\n```json\n[\n";
    
    for (size_t i = 0; i < stations.size(); i++) {
        const Station& station = stations[i];
        if (!station.isBusy()) continue;
        
        const Instruction& inst = station.getInstruction();
        string stationType = Station::getStationTypeName(station.getType());
        
        logFile << "    {\"type\": \"" << stationType << " (" << i << ")\", \"Instruction\": {\n";
        logFile << "        \"operation\": \"" << getOperationName(inst.getOperation()) << "\",\n";
        logFile << "        \"issuedAt\": " << inst.getIssuedAt() << ",\n";
        logFile << "        \"startedAt\": " << inst.getStartedAt() << ",\n";
        logFile << "        \"finishedAt\": " << inst.getFinishedAt() << ",\n";
        logFile << "        \"writtenAt\": " << inst.getWrittenAt() << "\n";
        logFile << "    }},\n";
    }
    logFile << "]\n```\n";  // Corrigido
}

void Log::logMemory(const std::vector<int>& memoria, int n) {
    if (!logFile.is_open()) return;
    logFile << "\n## Memoria (primeiras " << n << " posicoes)\n```json\n[ ";
    for (int i = 0; i < n && i < (int)memoria.size(); ++i) {
        logFile << memoria[i];
        if (i < n-1 && i < (int)memoria.size()-1) logFile << ", ";
    }
    logFile << " ]\n```\n";  // Corrigido
}