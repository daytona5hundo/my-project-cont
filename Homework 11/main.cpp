#include "Pokemon.h"
#include "PokemonClasses.h"
#include "Dito.h"
#include "printHeader.h"
using namespace std;

int main() {
    Pikachu pikachu(10);
    Charmander charmander(12);
    Bulbasaur bulbasaur(8);
    

   
    Pokemon* pokemons[] = { &pikachu, &charmander, &bulbasaur };

    printHeader("Pokemon Battle");

    for (int i = 0; i < 3; i++) {
        pokemons[i]->display(); 
        pokemons[i]->attack();   
        pokemons[i]->defend();   
        pokemons[i]->evolve();   
        cout << endl;
    }

    return 0;

    //used Chat to help with creating the pointer array and calling it effectively, was having trouble determining how best to create a for loop that called all the objects properly and it hlped that
}
