#include "Caterpie.hpp"
#include "Move.hpp"
#include <iostream>

// Constructor Initialization with specific damage attribute for Bug Bite
Caterpie::Caterpie(std::string p_name, int p_health, Move p_move) 
    : Pokemon(p_name, PokemonType::BUG, p_health), 
       // Assuming the Move has a getPower() method
      move(p_move) {}

// Bug Bite Method Implementation
void Caterpie::bugBite(Pokemon& target) {
    std::cout << name << " uses Bug Bite!\n";
    std::cout << "It's very effective!\n";
    target.takeDamage(bugBiteDamage);
}