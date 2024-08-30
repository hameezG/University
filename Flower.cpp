#include "Flower.h"

Flower::Flower(const string& name, const string& type, int bloomSize, bool isFragrant)
    : Plant(name, type), bloomSize(bloomSize), isFragrant(isFragrant) {}

Flower::~Flower() {}

void Flower::waterPlant() {
    waterLevel += 5; // Flowers require less water than other plants
    cout << "Watering " << name << ". Water level is now " << waterLevel << ".\n";
}

void Flower::provideSunlight() {
    sunlightExposure += 8; // Flowers need more sunlight
    cout << "Providing sunlight to " << name << ". Sunlight exposure is now " << sunlightExposure << ".\n";
}

void Flower::displayStatus() const {
    Plant::displayStatus();
    cout << "Bloom Size: " << bloomSize << "\n"
         << "Fragrant: " << (isFragrant ? "Yes" : "No") << "\n";
}
