// File: /User.cpp

#include "User.h"

User::User(const string& username, const string& password)
    : username(username), password(password), plantCount(0) {
    plants = new Plant*[20];  // Allow more plants per user
}

User::~User() {
    for (int i = 0; i < plantCount; i++) {
        delete plants[i];
    }
    delete[] plants;
}

void User::addPlant(Plant* plant) {
    if (plantCount < 20) {
        plants[plantCount++] = plant;
        cout << "Plant " << plant->getName() << " added to " << username << "'s collection.\n";
    } else {
        cout << "Cannot add more plants. Maximum limit reached.\n";
    }
}

void User::removePlant(const string& plantName) {
    int index = -1;
    for (int i = 0; i < plantCount; i++) {
        if (plants[i]->getName() == plantName) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        delete plants[index];
        for (int i = index; i < plantCount - 1; i++) {
            plants[i] = plants[i + 1];
        }
        plantCount--;
        cout << "Plant " << plantName << " removed from collection.\n";
    } else {
        cout << "Plant " << plantName << " not found.\n";
    }
}

void User::displayPlants() const {
    cout << username << "'s Plant Collection:\n";
    for (int i = 0; i < plantCount; i++) {
        plants[i]->displayStatus();
        cout << "-----------------------------\n";
    }
}

bool User::authenticate(const string& password) const {
    return this->password == password;
}

string User::getUsername() const {
    return username;
}

void User::managePlant(const string& plantName) {
    for (int i = 0; i < plantCount; i++) {
        if (plants[i]->getName() == plantName) {
            int action;
            cout << "Select an action for " << plantName << ":\n";
            cout << "1. Water Plant\n";
            cout << "2. Provide Sunlight\n";
            cout << "3. Fertilize\n";
            cout << "4. Prune\n";
            cout << "Enter your choice: ";
            cin >> action;

            switch (action) {
                case 1:
                    plants[i]->waterPlant();
                    break;
                case 2:
                    plants[i]->provideSunlight();
                    break;
                case 3:
                    plants[i]->fertilize();
                    break;
                case 4:
                    plants[i]->prune();
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            plants[i]->displayStatus();
            return;
        }
    }
    cout << "Plant " << plantName << " not found.\n";
}
