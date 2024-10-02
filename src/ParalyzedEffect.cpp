#include "ParalyzedEffect.hpp"
#include "Pokemon.hpp"

// Constructor - initialize the number of turns for the effect
ParalyzedEffect::ParalyzedEffect() {
    std::srand(std::time(0));  // Seed random number generator
    turnsLeft = std::rand() % 3 + 1;  // Set effect duration between 1 and 3 turns
}

// Apply the effect to a Pokémon
void ParalyzedEffect::applyEffect(Pokemon& target) {
    std::cout << target.name << " is paralyzed! It may not be able to move!\n";
}

std::string ParalyzedEffect::getEffectName() const {
    return "Paralyzed";
}

bool ParalyzedEffect::turnEndEffect(Pokemon& target) {
    if (turnsLeft <= 0) {
        clearEffect(target);
        return true;  // Pokémon can move after the effect ends
    }

    // Reduce the number of turns left
    turnsLeft--;

    // 25% chance that the Pokémon can't move
    int moveChance = std::rand() % 4;  // Generates a number between 0 and 3
    if (moveChance == 0) {
        std::cout << target.name << " is paralyzed and can't move!\n";
        return false;  // Pokémon can't move
    }
    
    return true;  // Pokémon can move
}

