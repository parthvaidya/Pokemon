#include "Caterpie.hpp"
#include <iostream>
#include <cstdlib>

// // Constructor Initialization with specific damage attribute for Bug Bite
// Caterpie::Caterpie(std::string p_name, int p_health, int p_bugBiteDamage)
//     : Pokemon(p_name, PokemonType::BUG, p_health), bugBiteDamage(p_bugBiteDamage) {}

// // Bug Bite Method Implementation
// void Caterpie::bugBite(Pokemon& target) {
//     std::cout << name << " uses Bug Bite!\n";
//     std::cout << "It's very effective!\n";
//     target.takeDamage(bugBiteDamage);
// }


Caterpie::Caterpie(std::string p_name, int p_health, int p_bugBiteDamage)
    : Pokemon(p_name, PokemonType::BUG, p_health), bugBiteDamage(p_bugBiteDamage) {
    // Initialize moves
    moves.push_back(Move("Bug Bite", bugBiteDamage));
    moves.push_back(Move("Tackle", 8));
    moves.push_back(Move("Sticky Web", 0)); // Special move (power 0 as it affects stats)
}

// Override attack method
void Caterpie::attack(Pokemon& target) {
    Move selectedMove = selectAndUseMove(target);
    // Handle special move effects
    if (selectedMove.name == "Sticky Web") {
        // Reduce target's attack power by 2
        // Assuming each Pokemon has an 'attackPower' attribute; if not, you'll need to implement it
        // For demonstration, we'll assume a simple reduction in health
        std::cout << "Sticky Web reduces " << target.name << "'s attack power!\n";
        // Implement attack power reduction logic here
        // Example: target.attackPower -= 2;
    }
}