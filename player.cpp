#include "player.hpp"
#include <iostream>

using namespace std;

player::player()
    : playerName("Unknown"), playerTypeName("None"), magicPts(50), strengthPts(10), health(100), luckVal(5) {}

player::player(string name, int magic, int strength, int health, int luck)
    : playerName(name), playerTypeName("None"), magicPts(magic), strengthPts(strength), health(health), luckVal(luck) {}

void player::displayStats() const {
    // display player's stats
    cout << "\nPlayer Name: " << playerName << endl;
    cout << "Player Type: " << playerTypeName << endl;
    cout << "Magic Points: " << magicPts << endl;
    cout << "Strength Points: " << strengthPts << endl;
    cout << "Health: " << health << endl;
    cout << "Luck Value: " << luckVal << endl;

    // Show inventory items
    cout << "Inventory: ";
    size_t inventorySize = inventory.size();
    if (inventorySize == 0) {
        cout << "No items equipped." << endl;
    } else {
        for (size_t i = 0; i < inventorySize; ++i) {
            cout << inventory[i];
            if (i < inventorySize - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void player::addItemToInventory(const string& item) {
    inventory.push_back(item);
}
