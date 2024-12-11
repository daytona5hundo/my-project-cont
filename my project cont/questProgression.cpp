#include "questProgression.hpp"
#include "combat.hpp"
#include <iostream>
#include <string>

using namespace std;

void questProgression::startQuest(player& p) {
    cout << "Starting quest for Player: " << p.playerName << "\nQuest Level: " << p.questLevel << endl;
    monster m;
    m.monsterGeneration(p.questLevel, p.luckVal);

    cout << "A new monster has appeared: " << m.monsterName << "!" << endl;
    m.displayStats();

    // Ask if the player wants to fight
    bool fightOn = false;
    string choice;
    cout << "Do you want to fight this monster? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        fightOn = true;
    }

    while (fightOn) {
        combatRound(p, m);

        if (m.health <= 0) {
            cout << m.monsterName << " has been defeated!" << endl;
            awardQuestPoints(p, m, true);
            break;
        } else if (p.health <= 0) {
            cout << p.playerName << " has been defeated by " << m.monsterName << "!" << endl;
            fightOn = false;
            break;
        }

        // Ask if the player wants to continue
        cout << "Do you want to keep fighting? (yes/no): ";
        cin >> choice;
        if (choice != "yes") {
            fightOn = false;
        }
    }

    if (!fightOn && p.health > 0) {
        cout << "You chose to flee from the battle." << endl;
    }
}

void questProgression::awardQuestPoints(player& p, monster& m, bool victory) {
    if (victory) {
        int basePoints = 20;
        if (m.health > p.health) {
            basePoints += 10; // Reward for defeating a stronger monster
        } else {
            basePoints -= 5; // Reduced reward for weaker monster
        }

        p.questPoints += basePoints;
        cout << "Player earned " << basePoints << " quest points!" << endl;
        p.levelUp();
    } else {
        cout << "No points awarded for losing..." << endl;
    }
}
