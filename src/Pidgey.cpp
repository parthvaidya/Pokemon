#include "Pidgey.hpp"
#include "PokemonType.hpp"
#include "Pokemon.hpp"
#include <iostream>

// Constructor Initialization with specific damage attribute for Wing Attack
Pidgey::Pidgey(std::string p_name, int p_health, int p_wingAttackDamage)
    : Pokemon(p_name, PokemonType::FLYING, p_health), wingAttackDamage(p_wingAttackDamage) {}

// Wing Attack Method Implementation
void Pidgey::wingAttack(Pokemon& target) {
    std::cout << name << " uses Wing Attack!\n";
    std::cout << "It's very effective!\n";
    target.takeDamage(wingAttackDamage);
}