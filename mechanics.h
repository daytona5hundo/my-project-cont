#ifndef MECHANICS_H
#define MECHANICS_H

#include "player.hpp"
#include <string>

using namespace std;


void playerDesignation(player& playerIn, int playertype);

// Assigns an item to the player's inventory, modifying their stats
void itemEquipping(const string& itemNamed, player& playerEquip);

// Rolls a die based on the player's luck value
int rollFunction(int luck);

// Displays the player's stats using the player's displayStats function
void displayPlayerStats(const player& playerInfo);

#endif // MECHANICS_H