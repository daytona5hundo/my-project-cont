#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
using namespace std;

// Abstract base class representing a generic Pokemon
class Pokemon {
protected:
    string name;
    int level;

public:
    Pokemon(const string& name, int level) : name(name), level(level) {}

    virtual ~Pokemon() {
        cout << "Your " << name << " has fainted!" << endl;
    }

    virtual void attack() const = 0; // Pure virtual function
    virtual void defend() const = 0; // Pure virtual function
    virtual void evolve() = 0;       // Pure virtual function

    void display() const {
        cout << "Name: " << name << ", Level: " << level << endl;
    }
};

#endif // POKEMON_H
