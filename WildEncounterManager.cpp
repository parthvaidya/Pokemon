#include "WildEncounterManager.hpp"
#include "Pokemon.hpp"
#include <ctime> 
#include <iostream> 
using namespace std;

// Implement the method to get a random Pokémon from grass
WildPokemon WildEncounterManager::getRandomPokemonFromGrass(const Grass& grass) {
    // Seed the randomness with the current time
    srand(static_cast<unsigned int>(time(0)));
    
    // Get a random index based on the number of wild Pokémon available
    int randomIndex = rand() % grass.wildPokemonList.size();
    return grass.wildPokemonList[randomIndex];
}

