#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "player.hpp"
#include "monster.hpp"

// function to calculate if an attack hits, considering luck value
bool attackSuccess(int luckVal);

// function for the player to attack
void playerAttack(player &p, monster &m);

// function for the monster to attack
void monsterAttack(monster &m, player &p);

// check if the player or monster is dead
void combatRound(player &p, monster &m);

#endif
