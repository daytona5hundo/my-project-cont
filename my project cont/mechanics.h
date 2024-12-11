#ifndef MECHANICS_H
#define MECHANICS_H

#include <string>
#include "player.hpp"
#include "monster.hpp"

void playerDesignation(player& playerIn, int playertype);  // Set up player stats based on type
void itemEquipping(const std::string& itemNamed, player& playerEquip);  // Equip an item and modify stats
int rollFunction(int luck);  // Simulate a dice roll influenced by luck
void displayPlayerStats(const player& playerInfo);  // Display player stats
void generateMonsterForCombat(monster& m, const player& p);  // Generate a monster based on questLevel and luck

#endif
