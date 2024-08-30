#ifndef CAREMANAGER_H
#define CAREMANAGER_H

#include "User.h"
#include "ExceptionHandling.h"
#include <iostream>

using namespace std;

class CareManager {
private:
    User* users[50];   
    int userCount;
    User* currentUser;

public:
    CareManager();
    ~CareManager();

    void createUser(const string& username, const string& password);
    void loginUser(const string& username, const string& password);
    void logoutUser();
    void addPlantToCurrentUser(Plant* plant);
    void removePlantFromCurrentUser(const string& plantName);
    void displayCurrentUserPlants() const;
    void manageCurrentUserPlant(const string& plantName);
};

#endif
