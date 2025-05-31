#ifndef REGISTRADOR_HPP
#define REGISTRADOR_HPP

class Registrador {
private:
    short value;
    short busyBy;

public:
    Registrador();
    bool isFree(short stationIndex = -1) const;
    short getValue() const;
    void setValue(short newValue);
    short getBusyBy() const;
    void setBusyBy(short stationIndex);
    void release();
};

#endif // REGISTRADOR_HPP