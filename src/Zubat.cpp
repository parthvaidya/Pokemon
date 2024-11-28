#include "Zubat.hpp"
#include <iostream>

// Constructor Initialization with specific damage attribute for Supersonic
Zubat::Zubat(std::string p_name, int p_health, Move p_move)
    : Pokemon(p_name, PokemonType::FLYING, p_health),
      move(p_move) {}
// Supersonic Method Implementation
void Zubat::supersonic(Pokemon& target) {
    std::cout << name << " uses Supersonic!\n";
    std::cout << "The attack confuses the target!\n";
    target.takeDamage(supersonicDamage);
}