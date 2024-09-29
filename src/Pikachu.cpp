#include "Pikachu.hpp"
#include "PokemonType.hpp"
#include <iostream>
#include <memory>

// Constructor Implementation
Pikachu::Pikachu()
    : Pokemon("Pikachu", PokemonType::ELECTRIC, 40), thunderShockDamage(15) {
    // Additional initialization if needed
}

// thunderShock Method Implementation
void Pikachu::thunderShock(Pokemon& target) {
    std::cout << name << " uses Thunder Shock on " << target.name << "!\n";
    target.takeDamage(thunderShockDamage);
}

// Clone Method Implementation
std::unique_ptr<Pokemon> Pikachu::clone() const {
    return std::make_unique<Pikachu>(*this);
}