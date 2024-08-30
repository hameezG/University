#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
private:
    int bloomSize;
    bool isFragrant;

public:
    Flower(const string& name, const string& type, int bloomSize, bool isFragrant);
    ~Flower();

    void waterPlant() override;
    void provideSunlight() override;
    void displayStatus() const override;
};

#endif
