#ifndef TREE_H
#define TREE_H

#include "Plant.h"

class Tree : public Plant {
private:
    int height;
    int age;

public:
    Tree(const string& name, const string& type, int height, int age);
    ~Tree();

    void waterPlant() override;
    void provideSunlight() override;
    void displayStatus() const override;
};

#endif
