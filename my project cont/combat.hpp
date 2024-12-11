#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "player.hpp"
#include "monster.hpp"

// Function prototypes
bool attackSuccess(int luckVal);
void playerAttack(player &p, monster &m);
void monsterAttack(monster &m, player &p);
void combatRound(player &p, monster &m);

#endif
