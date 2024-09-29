#ifndef GRASS_HPP
#define GRASS_HPP

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "PokemonType.hpp"  // Include this for the PokemonType enum
#include "Pokemon.hpp"
using namespace std;

class Pikachu;
// Struct to represent wild Pokémon
// struct WildPokemon {
//     string name;
//     PokemonType type;
//     int health;

//     WildPokemon(const string& p_name, PokemonType p_type, int p_health)
//         : name(p_name), type(p_type), health(p_health) {}
    
//     bool isFainted() const {
//         return health <= 0;
//     }

//     // Attack method for wild Pokémon
//     void attack(Pokemon& target) {
//         // Example attack logic; adjust based on your Pokémon class
//         int damage = 10; // Set some fixed damage or calculate based on type advantages
//         target.health -= damage; // Reduce health of the target Pokémon
//         cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
//     }
// };

// Struct to represent the Grass patch
struct Grass {
    string environmentType;  // Example: "Forest", "Cave", "Riverbank"
    // vector<WildPokemon> wildPokemonList;  // List of wild Pokémon that live in this grass
    int encounterRate;  // Likelihood of encountering a wild Pokémon, out of 100

    vector<unique_ptr<Pokemon>> wildPokemonList;
    Grass(string envType, int rate) : environmentType(envType), encounterRate(rate) {}

    // Method to add a Pokémon to the wildPokemonList
    void addPokemon(unique_ptr<Pokemon> pokemon) {
        wildPokemonList.push_back(move(pokemon));
    }
};

// Create instances of Grass
extern Grass forestGrass;
extern Grass caveGrass;

#endif