#ifndef DITO_H
#define DITO_H

#include "Pokemon.h"

// Dito class derived from Pokemon
class Dito : public Pokemon {
private:
    Pokemon* otherPokemon;

public:
    Dito(int level, Pokemon* pokemon) : Pokemon("Dito", level), otherPokemon(pokemon) {}

    void attack() const override {
        // Call the attack method of the passed Pokemon
        otherPokemon->attack();
    }
};

#endif // DITO_H
