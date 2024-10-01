#include "Pikachu.hpp"
#include "PokemonType.hpp"



#include <iostream>

// Constructor Implementation
Pikachu::Pikachu(std::string p_name, int p_health, Move p_move)
    : Pokemon(p_name, PokemonType::ELECTRIC, p_health),
      move(p_move) {}

// Thunder Shock Method Implementation
void Pikachu::thunderShock(Pokemon& target) {
    std::cout << name << " uses Thunder Shock!\n";
    std::cout << "It's super effective!\n";
    target.takeDamage(thunderShockDamage);
}