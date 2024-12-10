#include <iostream>
#include <string>
#include "player.hpp"
#include "monster.hpp"
#include "combat.hpp"
#include "mechanics.h"


using namespace std;

int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    string nameIn;

    player player1;
    cout << "Hello! Would you mind telling me your name, traveler?\n";
    cin >> nameIn;
    player1.playerName = nameIn;

    int playerDes;

    cout << "What type of hero are you?:\n0: Wizard\n1: Warrior\n2: Elemental\n3: Knight\n4: Sneak\n";
    cin >> playerDes;

    
    playerDesignation(player1, playerDes);  
    cout << "You have chosen: " << player1.playerTypeName << endl;

    cout << "You may equip three items to begin your inventory.\n Choose carefully, as they will change your stats, and can be helpful or detrimental!";
    for (int i = 0; i < 3; i++) {
        string itemChoice;
        cout << "Equip an item (Wand, Sword, Goblet, Knife, Chicken, Potion, Blood-Vial, Chestplate, Gloves, or Cat):\n ";
        cin >> itemChoice;

        itemEquipping(itemChoice, player1);
    }

    displayPlayerStats(player1);

    string YesOrNo;

    cout << "That's quite the stat chart you have there! \nHopefully it will be enough to prepare you for the orc onslaught in the west, or the dragon stirring in the east! That's why you're here, right?\n Y/N\n";

    cin >> YesOrNo;

    if (YesOrNo == "Y") {

        cout << "Oh thank heavens! Well I wouldn't want you to keep you from your grand quest!! Best of luck adventurer!\n \n";

    }
    else if (YesOrNo == "N") {

        cout << "Well that's too bad! \nYou probably gamble at least. \nRoll better than a 9 and I'll give you another item! \n Here, I'll roll for ya. Let's see what it is! \n";

        int luckRoll = rollFunction(player1.luckVal);
        cout << "You rolled a " << luckRoll << " based on your luck value.\n" << endl;

        if (luckRoll > 9) {

            cout << "Congrats! Choose another item!";
            string itemChoice;
            cout << "Equip an item (Wand, Sword, Goblet, Knife, Chicken, Potion, Blood Vial, Chestplate, Gloves, Cat): ";
            cin >> itemChoice;

            itemEquipping(itemChoice, player1);
            cout << "\nWell glad you got another item out of me! But you should really help us with our hero problems, especially considering we gave you free stuff.\n \n";

        }
        else {

            cout << "Wow, you just suck at everything haha! Nothing more for you here then, on with ya!\n";

        }

    }

    monster monster1("Goblin", 30, 10, 50, 5);  
    monster1.displayStats();
bool fightOn = true;
string answer {};

cout << "A goblin has appeared before you. This is a great opportunity to try out your new gear!\n";

cout << "Would you like to fight? Y/N\n";
cin >> answer;
if (answer == "Y"){
    fightOn = true;
}
else if(answer == "N"){
    fightOn = false;
}
    // Combat loop
    while (player1.health > 0 && monster1.health > 0 && fightOn) {
        combatRound(player1, monster1);
        cout << "Would you like to fight again? Y/N\n";
        cin >> answer;
        if (answer == "Y"){
            fightOn = true;
        }
        else if(answer == "N"){
            fightOn = false;
        }

    }
    if(player1.health >0){

        cout << "Great job!! Lets keep moving, there's more adventure ahead!!";
    }
    else if (player1.health == 0){

        cout << "Unfortunately, you've died. Should've chosen better gear, or maybe just been nice to the goblin guy I guess\n";
    }

    return 0;
}