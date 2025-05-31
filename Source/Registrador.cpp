#include "Registrador.hpp"

Registrador::Registrador() : value(0), busyBy(-1) {}

bool Registrador::isFree(short stationIndex) const {
    if (stationIndex != -1) {
        return (busyBy == -1 || busyBy == stationIndex);
    }
    return (busyBy == -1);
}

short Registrador::getValue() const { return value; }

void Registrador::setValue(short newValue) {
    value = newValue;
    release();
}

short Registrador::getBusyBy() const { return busyBy; }

void Registrador::setBusyBy(short stationIndex) {
    busyBy = stationIndex;
}

void Registrador::release() {
    busyBy = -1;
}