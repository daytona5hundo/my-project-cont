#include "monster.hpp"
#include <iostream>

using namespace std;

monster::monster()
    : monsterName("Goblin"), magicPts(30), strengthPts(5), health(50), luckVal(3) {}

monster::monster(string name, int magic, int strength, int health, int luck)
    : monsterName(name), magicPts(magic), strengthPts(strength), health(health), luckVal(luck) {}

void monster::displayStats() const {
    // Display monster's stats
    cout << "\nMonster Name: " << monsterName << endl;
    cout << "Magic Points: " << magicPts << endl;
    cout << "Strength Points: " << strengthPts << endl;
    cout << "Health: " << health << endl;
    cout << "Luck Value: " << luckVal << endl;
}
