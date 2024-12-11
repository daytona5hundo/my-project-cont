#include "mechanics.h"
#include "player.hpp"
#include "monster.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playerDesignation(player& playerIn, int playertype) {
    switch (playertype) {
    case 0:
        playerIn.magicPts = 15;
        playerIn.strengthPts = 5;
        playerIn.health = 20;
        playerIn.luckVal = 12;
        playerIn.playerTypeName = "Wizard";
        break;
    case 1:
        playerIn.magicPts = 5;
        playerIn.strengthPts = 15;
        playerIn.health = 12;
        playerIn.luckVal = 7;
        playerIn.playerTypeName = "Warrior";
        break;
    case 2:
        playerIn.magicPts = 12;
        playerIn.strengthPts = 10;
        playerIn.health = 10;
        playerIn.luckVal = 16;
        playerIn.playerTypeName = "Elemental";
        break;
    case 3:
        playerIn.magicPts = 10;
        playerIn.strengthPts = 16;
        playerIn.health = 15;
        playerIn.luckVal = 10;
        playerIn.playerTypeName = "Knight";
        break;
    case 4:
        playerIn.magicPts = 13;
        playerIn.strengthPts = 7;
        playerIn.health = 9;
        playerIn.luckVal = 14;
        playerIn.playerTypeName = "Sneak";
        break;
    default:
        cout << "Invalid player type." << endl;
        break;
    }
}

void itemEquipping(const string& itemNamed, player& playerEquip) {
    // Equip items and modify player stats accordingly
    if (itemNamed == "Wand") {
        playerEquip.magicPts += 7;
        playerEquip.luckVal += 3;
        cout << "The item Wand has been equipped, raising magic points by 7 and luck by 3." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Sword") {
        playerEquip.strengthPts += 5;
        playerEquip.luckVal += 2;
        cout << "The item Sword has been equipped, raising strength points by 5 and luck by 2." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Goblet") {
        playerEquip.health += 5;
        playerEquip.luckVal += 1;
        cout << "The item Goblet has been equipped, raising health by 5 and luck by 1." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Knife") {
        playerEquip.strengthPts += 3;
        playerEquip.magicPts += 1;
        cout << "The item Knife has been equipped, raising strength points by 3 and magic points by 1." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Chicken") {
        playerEquip.health += 8;
        playerEquip.luckVal -= 1;
        cout << "The item Chicken has been equipped, raising health by 8 but decreasing luck by 1." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Potion") {
        playerEquip.magicPts += 4;
        playerEquip.health += 3;
        cout << "The item Potion has been equipped, raising magic points by 4 and health by 3." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Blood-Vial") {
        playerEquip.strengthPts += 5;
        playerEquip.luckVal -= 3;
        cout << "The item Blood-Vial has been equipped, raising strength points by 5 but decreasing luck by 3." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Chestplate") {
        playerEquip.strengthPts += 3;
        playerEquip.health += 4;
        cout << "The item Chestplate has been equipped, raising strength points by 3 and health by 4." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Gloves") {
        playerEquip.luckVal += 4;
        playerEquip.strengthPts -= 2;
        cout << "The item Gloves has been equipped, raising luck by 4 but decreasing strength points by 2." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else if (itemNamed == "Cat") {
        playerEquip.luckVal += 6;
        playerEquip.health -= 4;
        cout << "The item Cat has been equipped, raising luck by 6 but decreasing health by 4." << endl;
        playerEquip.inventory.push_back(itemNamed);
    }
    else {
        cout << "Unknown item: " << itemNamed << endl;
    }
}

int rollFunction(int luck) {
    srand(static_cast<unsigned int>(time(0)));

    int rollVal = rand() % 10 + 1;  // Roll a value between 1 and 10

    // Adjust the roll value based on the player's luck
    switch (luck) {
    case 1:
        rollVal = (rollVal > 1) ? rollVal - 3 : rollVal;
        break;
    case 2:
        rollVal = (rollVal > 2) ? rollVal - 2 : rollVal;
        break;
    case 3:
    case 4:
        rollVal = (rollVal > 3) ? rollVal - 1 : rollVal;
        break;
    case 6:
        rollVal = (rollVal < 10) ? rollVal + 1 : rollVal;
        break;
    case 7:
        rollVal = (rollVal < 9) ? rollVal + 1 : rollVal;
        break;
    case 8:
        rollVal = (rollVal < 8) ? rollVal + 2 : rollVal;
        break;
    case 9:
        rollVal = (rollVal < 7) ? rollVal + 2 : rollVal;
        break;
    case 10:
        rollVal = (rollVal < 6) ? rollVal + 3 : rollVal;
        break;
    case 20:
        rollVal = 10;
        break;
    default:
        break;
    }

    return rollVal;
}

void displayPlayerStats(const player& playerInfo) {
    // Call player's displayStats function to show stats
    playerInfo.displayStats();
}
