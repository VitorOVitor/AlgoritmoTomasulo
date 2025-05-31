#ifndef LOG_HPP
#define LOG_HPP

#include "Station.hpp"
#include "Registrador.hpp"
#include <string>
#include <fstream>
#include <vector>

class Log {
private:
    static constexpr int REG_AMOUNT = 32;
    static constexpr int STATIONS_AMOUNT = 7;
    
    std::string logPath;
    std::ofstream logFile;
    
public:
    Log(const std::string& path = "output.md");
    ~Log();
    
    void setLogPath(const std::string& path);
    void newCycle(int cycle);
    
    enum class InstructionStep {
        Dispatched,
        Started,
        Completed,
        WroteToMemory
    };
    
    void logInstructionStep(InstructionStep step, int line);
    void logRegisterDependency(int dependency, int line);
    void logStationDependency(int line);
    void logRegisters(const std::vector<Registrador>& registers, const ReservationStations& stations);
    void logStations(const ReservationStations& stations);
    void logMemory(const std::vector<int>& memoria, int n = 8);
    
    static std::string getOperationName(Operation op);
};

#endif // LOG_HPP