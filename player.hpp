
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

class player {
public:
    std::string playerName;
    std::string playerTypeName;
    int magicPts;
    int strengthPts;
    int health;
    int luckVal;
    std::vector<std::string> inventory;  // Inventory to hold item names

    player();  //initialize with default values
    player(std::string name, int magic, int strength, int health, int luck); 

    void displayStats() const;  //display stats
    void addItemToInventory(const std::string& item);  // adding items
};

#endif
