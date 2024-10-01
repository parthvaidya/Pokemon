#include "Pikachu.hpp"
#include "PokemonType.hpp"



#include <iostream>
#include <cstdlib>

// Constructor Implementation
// Pikachu::Pikachu(std::string p_name, int p_health, int p_thunderShockDamage)
//     : Pokemon(p_name, PokemonType::ELECTRIC, p_health), thunderShockDamage(p_thunderShockDamage) {}

// // Thunder Shock Method Implementation
// void Pikachu::thunderShock(Pokemon& target) {
//     std::cout << name << " uses Thunder Shock!\n";
//     std::cout << "It's super effective!\n";
//     target.takeDamage(thunderShockDamage);
// }

Pikachu::Pikachu(std::string p_name, int p_health, int p_thunderShockDamage)
    : Pokemon(p_name, PokemonType::ELECTRIC, p_health), thunderShockDamage(p_thunderShockDamage) {
    // Initialize moves
    moves.push_back(Move("Thunder Shock", thunderShockDamage));
    moves.push_back(Move("Quick Attack", 10));
    moves.push_back(Move("Thunder Bolt", 20)); // Special move
}

// Override attack method
void Pikachu::attack(Pokemon& target) {
    Move selectedMove = selectAndUseMove(target);
    // Handle special move effects
    if (selectedMove.name == "Thunder Bolt") {
        // 20% chance to miss
        int chance = rand() % 100;
        if (chance < 20) {
            std::cout << "Thunder Bolt missed!\n";
            // Restore the damage done
            target.health += selectedMove.power;
            if (target.health > target.maxHealth) target.health = target.maxHealth;
        } else {
            std::cout << "Thunder Bolt hits hard!\n";
            // Damage was already applied in selectAndUseMove
        }
    }
}