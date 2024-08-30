#include "Cactus.h"

Cactus::Cactus(const string& name, const string& type, int needleLength)
    : Plant(name, type), needleLength(needleLength) {}

Cactus::~Cactus() {}

void Cactus::waterPlant() {
    waterLevel += 2; // Cacti need very little water
    cout << "Watering " << name << ". Water level is now " << waterLevel << ".\n";
}

void Cactus::provideSunlight() {
    sunlightExposure += 12; // Cacti thrive in sunlight
    cout << "Providing sunlight to " << name << ". Sunlight exposure is now " << sunlightExposure << ".\n";
}

void Cactus::displayStatus() const {
    Plant::displayStatus();
    cout << "Needle Length: " << needleLength << " cm\n";
}
