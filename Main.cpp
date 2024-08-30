#include "CareManager.h"
#include "Cactus.h"
#include "Flower.h"
#include "Tree.h"
#include "User.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\n--- Plant Care Manager ---\n";
    cout << "1. Create User\n";
    cout << "2. Login User\n";
    cout << "3. Logout User\n";
    cout << "4. Add Plant\n";
    cout << "5. Remove Plant\n";
    cout << "6. Display Plants\n";
    cout << "7. Manage Plant\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CareManager manager;
    int choice;
    string username, password, plantName, plantType;
    int needleLength, bloomSize, height, age;
    bool isFragrant;

    while (true) {
        try {
            displayMenu();
            cin >> choice;

            // Handling invalid input for menu choice
            if(cin.fail()) {
                throw runtime_error("Invalid input. Please enter a number.");
            }

            switch (choice) {
                case 1:
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    manager.createUser(username, password);
                    break;
                case 2:
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    manager.loginUser(username, password);
                    break;
                case 3:
                    manager.logoutUser();
                    break;
                case 4:
                    cout << "Enter plant type (Cactus/Flower/Tree): ";
                    cin >> plantType;
                    cout << "Enter plant name: ";
                    cin >> plantName;

                    if (plantType == "Cactus") {
                        cout << "Enter needle length: ";
                        cin >> needleLength;
                        manager.addPlantToCurrentUser(new Cactus(plantName, plantType, needleLength));
                    } else if (plantType == "Flower") {
                        cout << "Enter bloom size: ";
                        cin >> bloomSize;
                        cout << "Is it fragrant (1 for Yes, 0 for No)? ";
                        cin >> isFragrant;
                        manager.addPlantToCurrentUser(new Flower(plantName, plantType, bloomSize, isFragrant));
                    } else if (plantType == "Tree") {
                        cout << "Enter height: ";
                        cin >> height;
                        cout << "Enter age: ";
                        cin >> age;
                        manager.addPlantToCurrentUser(new Tree(plantName, plantType, height, age));
                    } else {
                        throw runtime_error("Unknown plant type.");
                    }
                    break;
                case 5:
                    cout << "Enter plant name to remove: ";
                    cin >> plantName;
                    manager.removePlantFromCurrentUser(plantName);
                    break;
                case 6:
                    manager.displayCurrentUserPlants();
                    break;
                case 7:
                    cout << "Enter plant name to manage: ";
                    cin >> plantName;
                    manager.manageCurrentUserPlant(plantName);
                    break;
                case 8:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
             
        }
    }

    return 0;
}
