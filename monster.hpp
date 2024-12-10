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

    monster();  // default constructor
    monster(std::string name, int magic, int strength, int health, int luck);  

    void displayStats() const;  //displays stats for monster
};

#endif
