#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H

#include "Pokemon.h"
using namespace std;


class PokemonTypes : public Pokemon {
public:
    PokemonTypes(const string& name, int level) : Pokemon(name, level) {}
    virtual ~PokemonTypes() = default;
};

// Electric 
class ElectricType : public PokemonTypes {
public:
    ElectricType(const string& name, int level) : PokemonTypes(name, level) {}
    ~ElectricType() override = default;
};

// Fire
class FireType : public PokemonTypes {
public:
    FireType(const string& name, int level) : PokemonTypes(name, level) {}
    ~FireType() override = default;
};

// Leaf
class LeafType : public PokemonTypes {
public:
    LeafType(const string& name, int level) : PokemonTypes(name, level) {}
    ~LeafType() override = default;
};


class Pikachu : public ElectricType {
public:
    Pikachu(int level) : ElectricType("Pikachu", level) {}

    void attack() const override {
        cout << name << " uses Thunderbolt!" << endl;
    }

    void defend() const override {
        cout << name << " defends with an Electric Shield!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Raichu!" << endl;
    }

    ~Pikachu() {
        cout << name << ", you put up a good fight. Return to the ball!" << endl;
    }
};


class Charmander : public FireType {
public:
    Charmander(int level) : FireType("Charmander", level) {}

    void attack() const override {
        cout << name << " uses Flamethrower!" << endl;
    }

    void defend() const override {
        cout << name << " blocks with a Wall of Fire!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Charmeleon!" << endl;
    }
};


class Bulbasaur : public LeafType {
public:
    Bulbasaur(int level) : LeafType("Bulbasaur", level) {}

    void attack() const override {
        cout << name << " uses Vine Whip!" << endl;
    }

    void defend() const override {
        cout << name << " creates a Shield of Leaves!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Ivysaur!" << endl;
    }
};

#endif // POKEMONTYPES_H
