#include "Pokemon.hpp"
#include "Utility.hpp"
#include "grass.hpp"
#include <iostream>


//refactorings 
// Pokemon::Pokemon() : name("Pikachu"), type(PokemonType::ELECTRIC), health(10) ,  maxHealth(10) {}

// Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health) 
//     : name(p_name), type(p_type), health(p_health), maxHealth(p_health) {}

// Pokemon::Pokemon(const Pokemon& other) 
//     : name(other.name), type(other.type), health(other.health), maxHealth(other.maxHealth) {}

// void Pokemon::takeDamage(int damage) {
//     health -= damage;
//     if (health < 0) {
//         health = 0; // Health shouldn't go below 0
//     }
//     std::cout << name << " takes " << damage << " damage. Current health: " << health << "/" << maxHealth << ".\n";
// }

// bool Pokemon::isFainted() const {
//     return health <= 0;
// }

// void Pokemon::attack(Pokemon& target) {
//     int damage = 10; // Fixed damage value for now
//     std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
//     target.takeDamage(damage);
// }

// std::string Pokemon::getTypeAsString() const {
//     switch (type) {
//         case PokemonType::FIRE: return "Fire";
//         case PokemonType::GRASS: return "Grass";
//         case PokemonType::WATER: return "Water";
//         case PokemonType::ELECTRIC: return "Electric";
//         default: return "Unknown";
//     }
// }

Pokemon::Pokemon() : name("Unknown"), type(PokemonType::NORMAL), health(10), maxHealth(10) {}

// Parameterized Constructor
Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health)
    : name(p_name), type(p_type), health(p_health), maxHealth(p_health) {}

// Copy Constructor
Pokemon::Pokemon(const Pokemon& other)
    : name(other.name), type(other.type), health(other.health), maxHealth(other.maxHealth), moves(other.moves) {}

// Method to get type as string
std::string Pokemon::getTypeAsString() const {
    switch (type) {
        case PokemonType::FIRE: return "Fire";
        case PokemonType::GRASS: return "Grass";
        case PokemonType::WATER: return "Water";
        case PokemonType::ELECTRIC: return "Electric";
        case PokemonType::NORMAL: return "Normal";
        case PokemonType::BUG: return "Bug";
        case PokemonType::FLYING: return "Flying";
        default: return "Unknown";
    }
}

// Method to take damage
void Pokemon::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0; // Health shouldn't go below 0
    }
    std::cout << name << " takes " << damage << " damage. Current health: " << health << "/" << maxHealth << ".\n";
}

// Check if Pokémon has fainted
bool Pokemon::isFainted() const {
    return health <= 0;
}

// Pure virtual attack method to be overridden by derived classes
void Pokemon::attack(Pokemon& target) {
    // This will be overridden by derived classes
}

// Function to select and use a move
Move Pokemon::selectAndUseMove(Pokemon& target) {
    if (moves.empty()) {
        std::cout << name << " has no moves to use!\n";
        // Return a default move
        return Move("Struggle", 10);
    }

    std::cout << "Choose a move:\n";
    for (size_t i = 0; i < moves.size(); ++i) {
        std::cout << i + 1 << ". " << moves[i].name << " (Power: " << moves[i].power << ")\n";
    }
    std::cout << "Enter the number of the move: ";

    int choice;
    std::cin >> choice;

    // Validate input
    if (choice < 1 || choice > static_cast<int>(moves.size())) {
        std::cout << "Invalid move choice. Using default attack.\n";
        return Move("Struggle", 10);
    }

    Move selectedMove = moves[choice - 1];
    std::cout << name << " uses " << selectedMove.name << "!\n";
    // For simplicity, apply damage here
    target.takeDamage(selectedMove.power);

    return selectedMove;
}

