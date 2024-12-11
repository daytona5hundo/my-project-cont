#ifndef QUESTPROGRESSION_HPP
#define QUESTPROGRESSION_HPP

#include "player.hpp"
#include "monster.hpp"
#include <iostream>

class questProgression {
public:
    void startQuest(player& p);
    bool battleMonster(player& p, monster& m);
    void awardQuestPoints(player& p, monster& m, bool victory);
};

#endif
