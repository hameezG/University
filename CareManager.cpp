#include "CareManager.h"
#include "ExceptionHandling.h"
#include <iostream>

using namespace std;

CareManager::CareManager() : userCount(0), currentUser(nullptr) {
    for (int i = 0; i < 50; i++) {
        users[i] = nullptr;
    }
}

CareManager::~CareManager() {
    for (int i = 0; i < userCount; i++) {
        delete users[i];
    }
}

void CareManager::createUser(const string& username, const string& password) {
    try {
        if (userCount < 50) {
            users[userCount++] = new User(username, password);
            cout << "User " << username << " created.\n";
        } else {
            throw std::runtime_error("Maximum user limit reached.");
        }
    } catch (const std::exception& e) {
        cout << "Error creating user: " << e.what() << endl;
    }
}

void CareManager::loginUser(const string& username, const string& password) {
    try {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUsername() == username && users[i]->authenticate(password)) {
                currentUser = users[i];
                cout << "Login successful. Welcome " << username << ".\n";
                return;
            }
        }
        throw AuthenticationException("Login failed. Incorrect username or password.");
    } catch (const AuthenticationException& e) {
        cout << e.what() << endl;
    }
}

void CareManager::logoutUser() {
    try {
        if (currentUser) {
            cout << "Logout successful. Goodbye " << currentUser->getUsername() << ".\n";
            currentUser = nullptr;
        } else {
            throw AuthenticationException("No user currently logged in.");
        }
    } catch (const AuthenticationException& e) {
        cout << e.what() << endl;
    }
}

void CareManager::addPlantToCurrentUser(Plant* plant) {
    try {
        if (currentUser) {
            currentUser->addPlant(plant);
        } else {
            throw AuthenticationException("No user currently logged in.");
        }
    } catch (const AuthenticationException& e) {
        cout << "Error adding plant: " << e.what() << endl;
    }
}

void CareManager::removePlantFromCurrentUser(const string& plantName) {
    try {
        if (currentUser) {
            currentUser->removePlant(plantName);
        } else {
            throw AuthenticationException("No user currently logged in.");
        }
    } catch (const AuthenticationException& e) {
        cout << "Error removing plant: " << e.what() << endl;
    }
}

void CareManager::displayCurrentUserPlants() const {
    try {
        if (currentUser) {
            currentUser->displayPlants();
        } else {
            throw AuthenticationException("No user currently logged in.");
        }
    } catch (const AuthenticationException& e) {
        cout << e.what() << endl;
    }
}

void CareManager::manageCurrentUserPlant(const string& plantName) {
    try {
        if (currentUser) {
            currentUser->managePlant(plantName);
        } else {
            throw AuthenticationException("No user currently logged in.");
        }
    } catch (const AuthenticationException& e) {
        cout << e.what() << endl;
    }
}


