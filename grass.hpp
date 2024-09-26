#ifndef GRASS_HPP
#define GRASS_HPP

#include <string>
#include <vector>
#include "PokemonType.hpp"  // Include this for the PokemonType enum

using namespace std;

// Struct to represent wild Pokémon
struct WildPokemon {
    string name;
    PokemonType type;
    int health;

    WildPokemon(const string& p_name, PokemonType p_type, int p_health)
        : name(p_name), type(p_type), health(p_health) {}
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