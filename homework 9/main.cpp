#include <iostream>
#include <string>

using namespace std;

class rock {
public:

    int rockHealth = 100;
    int damageVal = 0;

    void attack() {
        cout << "You punch the rock until you knuckles bleed. Why did you do that?" << endl;
        cout << "The rock is still at full health." << endl;
    }

    void attack(int damage) {
        cout << "You hit the rock with a tool of some kind, which in turn dealt " << damage << " damage!" << endl;
        damageVal = damage;
        rockHealth = rockHealth - damageVal;
        cout << "The rock now has only " << rockHealth << " health left." << endl;
    }

    void attack(string spellName, int damage) {
        cout << "You chose to cast " << spellName << " on the rock, dealing " << damage << " magical damage!" << endl;
        damageVal = damage;
        rockHealth = rockHealth - damageVal;
        cout << "The rock cries out in pain, now having only " << rockHealth << " health left." << endl;
    }

    
};

int main() {
    rock myRock;

    myRock.attack();
    myRock.attack(25);
    myRock.attack("Fireball!", 50);

    return 0;
}
