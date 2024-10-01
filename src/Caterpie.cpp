#include "Caterpie.hpp"
#include <iostream>

// Constructor Initialization with specific damage attribute for Bug Bite
Caterpie::Caterpie(std::string p_name, int p_health, int p_bugBiteDamage)
    : Pokemon(p_name, PokemonType::BUG, p_health), bugBiteDamage(p_bugBiteDamage) {}

// Bug Bite Method Implementation
void Caterpie::bugBite(Pokemon& target) {
    std::cout << name << " uses Bug Bite!\n";
    std::cout << "It's very effective!\n";
    target.takeDamage(bugBiteDamage);
}