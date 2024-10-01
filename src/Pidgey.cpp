#include "Pidgey.hpp"
#include "PokemonType.hpp"
#include "Pokemon.hpp"
#include <iostream>

// // Constructor Initialization with specific damage attribute for Wing Attack
// Pidgey::Pidgey(std::string p_name, int p_health, int p_wingAttackDamage)
//     : Pokemon(p_name, PokemonType::FLYING, p_health), wingAttackDamage(p_wingAttackDamage) {}

// // Wing Attack Method Implementation
// void Pidgey::wingAttack(Pokemon& target) {
//     std::cout << name << " uses Wing Attack!\n";
//     std::cout << "It's very effective!\n";
//     target.takeDamage(wingAttackDamage);
// }
// Constructor Initialization with specific damage attribute for Wing Attack
Pidgey::Pidgey(std::string p_name, int p_health, int p_wingAttackDamage)
    : Pokemon(p_name, PokemonType::FLYING, p_health), wingAttackDamage(p_wingAttackDamage) {
    // Initialize moves
    moves.push_back(Move("Wing Attack", wingAttackDamage));
    moves.push_back(Move("Quick Attack", 10));
    moves.push_back(Move("Gust", 18)); // Special move
}

// Override attack method
void Pidgey::attack(Pokemon& target) {
    Move selectedMove = selectAndUseMove(target);
    // Handle special move effects
    if (selectedMove.name == "Gust") {
        // 10% chance to end the battle by blowing away the opponent
        int chance = rand() % 100;
        if (chance < 10) {
            std::cout << "Gust was so strong that it blew away " << target.name << "! You won the battle!\n";
            target.health = 0; // Faint the target
        } else {
            std::cout << "Gust hits the opponent!\n";
            // Damage was already applied in selectAndUseMove
        }
    }
}