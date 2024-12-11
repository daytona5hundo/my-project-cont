#include "questProgression.hpp"
#include "mechanics.h"
#include "player.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize player
    string playerName;
    cout << "Enter your player name: ";
    cin >> playerName;

    int playerType;
    cout << "Choose your player subclass:\n";
    cout << "0: Wizard\n1: Warrior\n2: Elemental\n3: Knight\n4: Sneak\n";
    cin >> playerType;

    player p(playerName, 0, 0, 0, 0); // Temporary initialization
    playerDesignation(p, playerType); // Set subclass stats
    cout << "\nPlayer Stats after Subclass Selection:\n";
    p.displayStats();

    // Choose three items to equip
    cout << "\nChoose three items to equip from the following:\n";
    cout << "Wand, Sword, Goblet, Knife, Chicken, Potion, Blood-Vial, Chestplate, Gloves, Cat\n";

    const vector<string> validItems = {"Wand", "Sword", "Goblet", "Knife", "Chicken", "Potion", "Blood-Vial", "Chestplate", "Gloves", "Cat"};

    for (int i = 0; i < 3; ++i) {
        string itemName;
        bool validChoice = false;

        while (!validChoice) {
            cout << "Enter item " << (i + 1) << ": ";
            cin >> itemName;
            
            if (find(validItems.begin(), validItems.end(), itemName) != validItems.end()) {
                itemEquipping(itemName, p);
                validChoice = true;
            } else {
                cout << "Invalid item choice. Please choose an item from the list." << endl;
            }
        }
    }

    cout << "\nPlayer Stats after Equipping Items:\n";
    p.displayStats();

    // Initialize quest progression
    questProgression quest;

    // Player will fight three monsters as part of the quest
    for (int i = 1; i <= 3; ++i) {
        cout << "\n--- Monster " << i << " Encounter ---\n";
        quest.startQuest(p);

        if (p.health <= 0) {
            cout << "\nGame Over! " << p.playerName << " was defeated during the quest." << endl;
            return 0;
        }
    }

    cout << "\nCongratulations! You have completed the quest and survived three encounters!" << endl;
    p.displayStats();

    return 0;
}
