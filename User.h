#ifndef USER_H
#define USER_H

#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include "Cactus.h"
#include <iostream>
 

using namespace std;



class User {
private:
    string username;
    string password;
    Plant** plants;
    int plantCount;

public:
    User(const string& username, const string& password);
    ~User();

    string getPassword() const;
    void addPlant(Plant* plant);
    void removePlant(const string& plantName);
    void displayPlants() const;
    bool authenticate(const string& password) const;
    string getUsername() const;
    void managePlant(const string& plantName);
};

#endif
