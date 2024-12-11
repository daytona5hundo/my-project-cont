#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>

class monster {
public:
    std::string monsterName;
    int magicPts;
    int strengthPts;
    int health;
    int luckVal;

    monster();  // Default constructor
    monster(std::string name, int magic, int strength, int health, int luck);

    void displayStats() const;  // Displays stats for monster
    void monsterGeneration(int playerQuestLevel, int playerLuck); // Generate stats based on player
};

#endif