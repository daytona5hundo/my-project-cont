#include "player.hpp"
#include <iostream>

using namespace std;

player::player()
    : playerName("Unknown"), playerTypeName("None"), magicPts(50), strengthPts(10), health(100), luckVal(5), questLevel(1), questPoints(0), QuestPointsRequired(100) {}

player::player(string name, int magic, int strength, int health, int luck)
    : playerName(name), playerTypeName("None"), magicPts(magic), strengthPts(strength), health(health), luckVal(luck), questLevel(1), questPoints(0), QuestPointsRequired(100) {}

void player::displayStats() const {
    cout << "\nPlayer Name: " << playerName << endl;
    cout << "Player Type: " << playerTypeName << endl;
    cout << "Magic Points: " << magicPts << endl;
    cout << "Strength Points: " << strengthPts << endl;
    cout << "Health: " << health << endl;
    cout << "Luck Value: " << luckVal << endl;
    cout << "Quest Level: " << questLevel << endl;
    cout << "Quest Points: " << questPoints << "/" << QuestPointsRequired << endl;

    cout << "Inventory: ";
    if (inventory.empty()) {
        cout << "No items equipped." << endl;
    } else {
        for (const auto& item : inventory) {
            cout << item << " ";
        }
        cout << endl;
    }
}

void player::addItemToInventory(const string& item) {
    inventory.push_back(item);
}

void player::levelUp() {
    if (questPoints >= QuestPointsRequired) {
        ++questLevel;
        questPoints = 0;
        QuestPointsRequired += 50; // Increment required points for next level

        // Increment player stats
        magicPts += 5;
        strengthPts += 3;
        health += 10;
        luckVal += 1;

        cout << "Congratulations! You have leveled up to level " << questLevel << "!" << endl;
    }
}
