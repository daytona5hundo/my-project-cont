#include "monster.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

monster::monster()
    : monsterName("Goblin"), magicPts(30), strengthPts(5), health(50), luckVal(3) {}

monster::monster(string name, int magic, int strength, int health, int luck)
    : monsterName(name), magicPts(magic), strengthPts(strength), health(health), luckVal(luck) {}

void monster::displayStats() const {
    cout << "\nMonster Name: " << monsterName << endl;
    cout << "Magic Points: " << magicPts << endl;
    cout << "Strength Points: " << strengthPts << endl;
    cout << "Health: " << health << endl;
    cout << "Luck Value: " << luckVal << endl;
}

void monster::monsterGeneration(int playerQuestLevel, int playerLuck) {
    srand(time(0));
    int deviation = (rand() % 7) - 3; // Range: -3 to +3
    int adjustedLevel = playerQuestLevel + deviation;

    if (adjustedLevel < 1) adjustedLevel = 1;

    // Assign stats based on adjusted quest level
    health = 40 + (adjustedLevel * 10);
    strengthPts = 5 + (adjustedLevel * 3);
    magicPts = 20 + (adjustedLevel * 2);

    // Adjust monster strength based on player's luck
    if (playerLuck < 5) {
        health += 10;
        strengthPts += 2;
    } else if (playerLuck > 7) {
        health -= 10;
        strengthPts -= 2;
    }

    luckVal = rand() % 10 + 1;

    // Assign a random name from the pool
    const string monsterNames[] = {"Basilisk", "Troll", "Imp", "Dark Elf", "Forest Spirit", "Dragon"};
    int nameIndex = rand() % (sizeof(monsterNames) / sizeof(monsterNames[0]));
    monsterName = monsterNames[nameIndex];
}
