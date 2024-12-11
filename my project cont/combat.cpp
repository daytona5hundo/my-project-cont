#include "combat.hpp"
#include "mechanics.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool attackSuccess(int luckVal) {
    int roll = rand() % 20 + 1; 
    return roll <= luckVal;  // If roll is less than or equal to luck, it's a hit
}

void playerAttack(player &p, monster &m) {
    if (attackSuccess(p.luckVal)) {
        int damage = p.strengthPts + rand() % 5;  // strength value + random bonus damage
        m.health -= damage;
        cout << p.playerName << " attacks " << m.monsterName << " for " << damage << " damage." << endl;
    } else {
        cout << p.playerName << " missed the attack!" << endl;
    }
}

void monsterAttack(monster &m, player &p) {
    if (attackSuccess(m.luckVal)) {
        int damage = m.strengthPts + rand() % 5;  // strength + bonus damage
        p.health -= damage;
        cout << m.monsterName << " attacks " << p.playerName << " for " << damage << " damage." << endl;
    } else {
        cout << m.monsterName << " missed the attack!" << endl;
    }
}

void combatRound(player &p, monster &m) {
    cout << "\n[Combat Round]" << endl;
    playerAttack(p, m);
    if (m.health <= 0) {
        cout << m.monsterName << " has been slain by " << p.playerName << "!" << endl;
        return;  // Monster is dead, end the round
    }

    monsterAttack(m, p);
    if (p.health <= 0) {
        cout << p.playerName << " has been slain by " << m.monsterName << "!" << endl;
        return;  // Player is dead, end the round
    }

    cout << "End of round stats:" << endl;
    p.displayStats();
    m.displayStats();
}
