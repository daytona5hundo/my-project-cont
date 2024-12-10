#include "combat.hpp"
#include "mechanics.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// simulates attack success based on luckVal
bool attackSuccess(int luckVal) {
    int roll = rand() % 20 + 1; 
    return roll <= luckVal;  // If roll is less than or equal to luck, it's a hit
}

// player attacks
void playerAttack(player &p, monster &m) {
    if (attackSuccess(p.luckVal)) {
        int damage = p.strengthPts + rand() % 5;  // strength value + random bonus damage
        m.health -= damage;
        std::cout << p.playerName << " attacks " << m.monsterName << " for " << damage << " damage.\n";
    } else {
        std::cout << p.playerName << " missed the attack!\n";
    }
}

// monster attacks
void monsterAttack(monster &m, player &p) {
    if (attackSuccess(m.luckVal)) {
        int damage = m.strengthPts + rand() % 5;  // strength + bonus damage
        p.health -= damage;
        std::cout << m.monsterName << " attacks " << p.playerName << " for " << damage << " damage.\n";
    } else {
        std::cout << m.monsterName << " missed the attack!\n";
    }
}

// checks after each attack if the player or monster is dead
void combatRound(player &p, monster &m) {
    playerAttack(p, m);
    if (m.health <= 0) {
        std::cout << m.monsterName << " has been slain by " << p.playerName << "!\n";
        return;  // Monster is dead, end the round
    }

    monsterAttack(m, p);
    if (p.health <= 0) {
        std::cout << p.playerName << " has been slain by " << m.monsterName << "!\n";
        return;  // Player is dead, end the round
    }

    std::cout << "End of round stats:\n";
    p.displayStats();
    m.displayStats();
}
