#include "Tree.h"

Tree::Tree(const string& name, const string& type, int height, int age)
    : Plant(name, type), height(height), age(age) {}

Tree::~Tree() {}

void Tree::waterPlant() {
    waterLevel += 20; // Trees need a lot of water
    cout << "Watering " << name << ". Water level is now " << waterLevel << ".\n";
}

void Tree::provideSunlight() {
    sunlightExposure += 10;
    cout << "Providing sunlight to " << name << ". Sunlight exposure is now " << sunlightExposure << ".\n";
}

void Tree::displayStatus() const {
    Plant::displayStatus();
    cout << "Height: " << height << " ft\n"
         << "Age: " << age << " years\n";
}
