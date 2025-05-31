#ifndef STATION_HPP
#define STATION_HPP

#include "Instruction.hpp"
#include <vector>
#include <string>

enum class StationType { Load, Store, Adder, Multiplier };

class Station {
private:
    bool busy;
    StationType type;
    Instruction instruction;
    int debugInstructionLine;
    
public:
    Station(StationType stationType = StationType::Adder);
    
    bool isBusy() const;
    StationType getType() const;
    const Instruction& getInstruction() const;
    int getDebugInstructionLine() const;
    
    void setBusy(bool isBusy);
    void setInstruction(const Instruction& inst);
    void setDebugInstructionLine(int line);
    
    static StationType getDispatchTarget(Operation op);
    static std::string getStationTypeName(StationType type);
    void debugPrint() const;
};

class ReservationStations {
private:
    std::vector<Station> stations;
    
public:
    ReservationStations();
    int findNonBusyStation(StationType type) const;
    int dispatchInstruction(const Instruction& instruction, int clock, int instructionPosInLine);
    Station& operator[](size_t index);
    const Station& operator[](size_t index) const;
    size_t size() const;
};

#endif // STATION_HPP