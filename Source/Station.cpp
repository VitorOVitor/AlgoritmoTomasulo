#include "Station.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

Station::Station(StationType stationType) 
    : busy(false), type(stationType), debugInstructionLine(-1) {}

bool Station::isBusy() const { return busy; }
StationType Station::getType() const { return type; }
const Instruction& Station::getInstruction() const { return instruction; }
int Station::getDebugInstructionLine() const { return debugInstructionLine; }

void Station::setBusy(bool isBusy) { busy = isBusy; }
void Station::setInstruction(const Instruction& inst) { instruction = inst; }
void Station::setDebugInstructionLine(int line) { debugInstructionLine = line; }

StationType Station::getDispatchTarget(Operation op) {
    switch(op) {
        case Operation::ADD:
        case Operation::SUB:
            return StationType::Adder;
        case Operation::LW:
            return StationType::Load;
        case Operation::SW:
            return StationType::Store;
        case Operation::MUL:
        case Operation::DIV:
            return StationType::Multiplier;
        default:
            throw invalid_argument("Invalid operation for dispatch target");
    }
}

string Station::getStationTypeName(StationType type) {
    switch(type) {
        case StationType::Adder: return "ADDER";
        case StationType::Load: return "LOAD";
        case StationType::Store: return "STORE";
        case StationType::Multiplier: return "MULTIPLIER";
        default: return "UNKNOWN";
    }
}

void Station::debugPrint() const {
    cout << "* Reservation Station: " << getStationTypeName(type) << "\n";
    cout << "[Busy]: " << (busy ? "true" : "false") << "\n";
    if (busy) {
        cout << "* Instruction in Station:\n";
        instruction.debugPrint();
    }
}

ReservationStations::ReservationStations() {
    stations = {
        Station(StationType::Adder),
        Station(StationType::Adder),
        Station(StationType::Multiplier),
        Station(StationType::Load),
        Station(StationType::Load),
        Station(StationType::Store),
        Station(StationType::Store)
    };
}

int ReservationStations::findNonBusyStation(StationType type) const {
    for (size_t i = 0; i < stations.size(); i++) {
        if (stations[i].getType() == type && !stations[i].isBusy()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int ReservationStations::dispatchInstruction(const Instruction& instruction, int clock, int instructionPosInLine) {
    StationType stationType = Station::getDispatchTarget(instruction.getOperation());
    int stationIndex = findNonBusyStation(stationType);
    
    if (stationIndex == -1) 
        return -1;
    
    Station& station = stations[stationIndex];
    station.setBusy(true);
    
    Instruction instCopy = instruction;
    instCopy.setIssuedAt(clock);
    station.setInstruction(instCopy);
    station.setDebugInstructionLine(instructionPosInLine);
    
    return stationIndex;
}

Station& ReservationStations::operator[](size_t index) {
    if (index >= stations.size()) 
        throw out_of_range("Station index out of range");
    return stations[index];
}

const Station& ReservationStations::operator[](size_t index) const {
    if (index >= stations.size()) 
        throw out_of_range("Station index out of range");
    return stations[index];
}

size_t ReservationStations::size() const {
    return stations.size();
}