#include "Plant.h"

Plant::Plant(const string& name, const string& type)
    : name(name), type(type), waterLevel(0), sunlightExposure(0), isFertilized(false), isPruned(false) {}

Plant::~Plant() {}

void Plant::waterPlant() {
    waterLevel += 10;
    cout << "Watering " << name << ". Water level is now " << waterLevel << ".\n";
}

void Plant::provideSunlight() {
    sunlightExposure += 5;
    cout << "Providing sunlight to " << name << ". Sunlight exposure is now " << sunlightExposure << ".\n";
}

void Plant::fertilize() {
    isFertilized = true;
    cout << name << " has been fertilized.\n";
}

void Plant::prune() {
    isPruned = true;
    cout << name << " has been pruned.\n";
}

void Plant::displayStatus() const {
    cout << "Plant: " << name << "\nType: " << type
         << "\nWater Level: " << waterLevel
         << "\nSunlight Exposure: " << sunlightExposure
         << "\nFertilized: " << (isFertilized ? "Yes" : "No")
         << "\nPruned: " << (isPruned ? "Yes" : "No") << "\n";
}

string Plant::getName() const { return name; }
string Plant::getType() const { return type; }
