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
    int questLevel;  // New attribute for quest level
    int questPoints; // New attribute for quest points
    int QuestPointsRequired; // Points required for next level
    std::vector<std::string> inventory;  // Inventory to hold item names

    player();  // Initialize with default values
    player(std::string name, int magic, int strength, int health, int luck);

    void displayStats() const;  // Display stats
    void addItemToInventory(const std::string& item);  // Adding items
    void levelUp(); // Increment stats and quest level
};

#endif