#ifndef PLANT_H
#define PLANT_H

#include <iostream>
 

using namespace std;

class Plant {
protected:
    string name;
    string type;
    int waterLevel;
    int sunlightExposure;
    bool isFertilized;
    bool isPruned;

public:
    Plant(const string& name, const string& type);
    virtual ~Plant();

    virtual void waterPlant();
    virtual void provideSunlight();
    virtual void fertilize();
    virtual void prune();
    virtual void displayStatus() const;

    string getName() const;
    string getType() const;
};

#endif
