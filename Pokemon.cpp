#include "Pokemon.hpp"
#include "Utility.hpp"
#include <iostream>


//refactorings 
Pokemon::Pokemon() : name("Pikachu"), type(PokemonType::ELECTRIC), health(10) {}

Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health) 
    : name(p_name), type(p_type), health(p_health) {}

Pokemon::Pokemon(const Pokemon& other) 
    : name(other.name), type(other.type), health(other.health) {}

std::string Pokemon::getTypeAsString() const {
    switch (type) {
        case PokemonType::FIRE: return "Fire";
        case PokemonType::GRASS: return "Grass";
        case PokemonType::WATER: return "Water";
        case PokemonType::ELECTRIC: return "Electric";
        default: return "Unknown";
    }
}