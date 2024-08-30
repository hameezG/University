#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"

class Cactus : public Plant {
private:
    int needleLength;

public:
    Cactus(const string& name, const string& type, int needleLength);
    ~Cactus();

    void waterPlant() override;
    void provideSunlight() override;
    void displayStatus() const override;
};

#endif
