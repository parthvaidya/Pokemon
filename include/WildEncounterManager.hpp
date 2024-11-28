#ifndef WILD_ENCOUNTER_MANAGER_HPP
#define WILD_ENCOUNTER_MANAGER_HPP

#include "grass.hpp"  // Include the Grass header
#include <vector>
#include <cstdlib>

// Declare grass areas as extern variables
extern Grass forestGrass;
extern Grass caveGrass;

class WildEncounterManager {
public:
    // Method to get a random Pokémon from the grass
    WildPokemon getRandomPokemonFromGrass(const Grass& grass);
};

#endif
