#include "WildEncounterManager.hpp"
#include "Pokemon.hpp"
#include <ctime>  // For time()
#include <memory>

// // Implement the method to get a random Pokémon from grass
// WildPokemon WildEncounterManager::getRandomPokemonFromGrass(const Grass& grass) {
//     // Seed the randomness with the current time
//     std::srand(static_cast<unsigned int>(std::time(0)));
    
//     // Get a random index based on the number of wild Pokémon available
//     int randomIndex = std::rand() % grass.wildPokemonList.size();
//     return grass.wildPokemonList[randomIndex];
// }


unique_ptr<Pokemon> WildEncounterManager::getRandomPokemonFromGrass(const Grass& grass) {
    // Seed the randomness only once
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }

    if (grass.wildPokemonList.empty()) {
        return nullptr; // No Pokémon to encounter
    }

    // Generate a random index based on the number of wild Pokémon available
    int randomIndex = std::rand() % grass.wildPokemonList.size();

    // Clone the selected Pokémon
    const Pokemon* selectedPokemon = grass.wildPokemonList[randomIndex].get();
    return selectedPokemon->clone(); // Assuming clone() is implemented
}