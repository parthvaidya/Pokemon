#include "Zubat.hpp"
#include <iostream>
#include <cstdlib>

// Constructor Initialization with specific damage attribute for Supersonic
// Zubat::Zubat(std::string p_name, int p_health, int p_supersonicDamage)
//     : Pokemon(p_name, PokemonType::FLYING, p_health), supersonicDamage(p_supersonicDamage) {}

// // Supersonic Method Implementation
// void Zubat::supersonic(Pokemon& target) {
//     std::cout << name << " uses Supersonic!\n";
//     std::cout << "The attack confuses the target!\n";
//     target.takeDamage(supersonicDamage);
// }


// Constructor Initialization with specific damage attribute for Supersonic
Zubat::Zubat(std::string p_name, int p_health, int p_supersonicDamage)
    : Pokemon(p_name, PokemonType::FLYING, p_health), supersonicDamage(p_supersonicDamage) {
    // Initialize moves
    moves.push_back(Move("Leech Life", 12));
    moves.push_back(Move("Quick Attack", 10));
    moves.push_back(Move("Leech Life", 15)); // Special move (reusing name for demonstration)
}

// Override attack method
void Zubat::attack(Pokemon& target) {
    Move selectedMove = selectAndUseMove(target);
    // Handle special move effects
    if (selectedMove.name == "Leech Life") {
        // Restore health based on damage dealt
        int damageDealt = selectedMove.power;
        health += damageDealt / 2; // Restore half of the damage dealt
        if (health > maxHealth) health = maxHealth;
        std::cout << name << " restores " << damageDealt / 2 << " health points!\n";
    }
}