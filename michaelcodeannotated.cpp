#include <iostream>
#include <string>
#include <iomanip>
#include "Project 1.hpp" // consider renaming this to MichaelsProject.cpp to delineate difference
using namespace std;

// stats variables like name, health, armor, etc.
string name;
int e_health = 100;    
int health = 100;      
int clas;              
int armor;             
int mana;              
int damage;            
string invintory[6];   // inventory, spelling "inventory" might be better

// this function equips an item to a specific inventory slot
void equip(int num, int slot)
{
    // maybe use an enum here instead of hardcoding the items
    switch(num)
    {
        case 1: invintory[slot] = "L-Mana"; break;
        case 2: invintory[slot] = "M-Mana"; break;
        case 3: invintory[slot] = "S-Mana"; break;
        case 4: invintory[slot] = "L-Health"; break;
        case 5: invintory[slot] = "M-Health"; break;
        case 6: invintory[slot] = "S-Health"; break;
        case 7: invintory[slot] = "L-Bomb"; break;
        case 8: invintory[slot] = "M-Bomb"; break;
        case 9: invintory[slot] = "S-Bomb"; break;
        case 10: invintory[slot] = "Super Pot"; break;
    }
}

// this function runs the main game loop
int main()
{
    int num;

    // display the welcome message
    cout << setw(114) << "WELCOME TO DUNGEONS AND NOT DRAGONS!!!!!!!" << endl << endl;
    cout << setw(101) << "CHOSE YOUR CLASS!" << endl << endl;
    cout << setw(110) << "Wizard - 1 Knight - 2 Assasin - 3" << endl;
    cin >> num;

    // ask for player's name
    cout << "Chose your name: ";
    cin >> name;

    // set stats based on the class chosen
    switch(num)
    {
        case 1:  clas = 1; armor = 0; mana = 100; damage = 15; break;  // wizard
        case 2:  clas = 2; armor = 8; mana = 0; damage = 20; break;    // knight
        case 3:  clas = 3; armor = 4; mana = 0; damage = 15; break;    // assassin
    }

    // let the player choose 5 items for their inventory
    cout << "\nYou may pick 5 items to aid in your battle!" << endl;
    cout << "Choose wisely (Enter #)" << endl;
    string items[10] = {"L-Mana","M-Mana","S-Mana","L-Health","M-Health","S-Health","L-Bomb","M-Bomb","S-Bomb","Super Pot"};
    
    for (int i = 1; i <= size(items); i++) // maybe use sizeof(items) instead of size()
    {
        cout << i << ": " << items[i-1] << endl;
    }
    
    cout << endl;
    
    // let player pick items for the inventory
    for (int i = 1; i <= 5; i++)  
    {
        cout << "Slot " << i << ": ";
        cin >> num;
        equip(num, i);  // equip the selected item
    }

    // store the address of inventory slot 1
    string* adress = &invintory[1];  
    int temp;

    // battle loop, keeps running until health is 0
    while (health > 0 && e_health > 0)
    {
        fight(adress, &health, &e_health, &mana); // could split "fight" into a different function
        cout << "\nAttack (1)  Use Gear (2): ";
        cin >> temp;
        
        switch (temp) 
        {
            case 1: 
            {
                e_health -= damage;  // attack the enemy
                break;
            }
            case 2:
            {
                cout << "Pick slot: ";
                cin >> temp;
                effect(invintory[temp], &health, &e_health, &mana);  // use item from inventory
                invintory[temp] = " "; // clear item after use
                break;
            }
        }
        
        health -= (30 - armor);  // damage over time from enemy, reduce by armor
    }

    // final check after the loop
    fight(adress, &health, &e_health, &mana);

    // check who won and print the result
    if (health <= 0)
    {
        cout << "\n\nYou suck" << endl;
    }
    else if (e_health <= 0)
    {
        cout << "\n\nYou Win!!" << endl;
    }

    return 0;
}
