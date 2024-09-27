#ifndef GRASS_HPP
#define GRASS_HPP

#include <string>
#include <vector>
#include "PokemonType.hpp"  // Include this for the PokemonType enum
#include "Pokemon.hpp"

#include <iostream>

// Struct to represent wild Pokémon
struct WildPokemon {
    string name;
    PokemonType type;
    int health;

    WildPokemon(const string& p_name, PokemonType p_type, int p_health)
        : name(p_name), type(p_type), health(p_health) {}
    
    bool isFainted() const {
        return health <= 0;
    }

    // Attack method for wild Pokémon
    void attack(Pokemon& target) {
        // Example attack logic; adjust based on your Pokémon class
        int damage = 10; // Set some fixed damage or calculate based on type advantages
        target.health -= damage; // Reduce health of the target Pokémon
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
    }
};

// Struct to represent the Grass patch
struct Grass {
    string environmentType;  // Example: "Forest", "Cave", "Riverbank"
    vector<WildPokemon> wildPokemonList;  // List of wild Pokémon that live in this grass
    int encounterRate;  // Likelihood of encountering a wild Pokémon, out of 100
};

// Create instances of Grass
extern Grass forestGrass;
extern Grass caveGrass;

#endif