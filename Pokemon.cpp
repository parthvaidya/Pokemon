#include "Pokemon.hpp"
#include "Utility.hpp"
#include "grass.hpp"
#include <iostream>
using namespace std;


//refactorings 
Pokemon::Pokemon() : name("Pikachu"), type(PokemonType::ELECTRIC), health(10) ,  maxHealth(10) {}

Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health) 
    : name(p_name), type(p_type), health(p_health), maxHealth(p_health) {}

Pokemon::Pokemon(const Pokemon& other) 
    : name(other.name), type(other.type), health(other.health), maxHealth(other.maxHealth) {}

void Pokemon::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0; // Health shouldn't go below 0
    }
    cout << name << " takes " << damage << " damage. Current health: " << health << "/" << maxHealth << ".\n";
}

bool Pokemon::isFainted() const {
    return health <= 0;
}

void Pokemon::attack(Pokemon& target) {
    int damage = 10; // Fixed damage value for now
    cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
    target.takeDamage(damage);
}

string Pokemon::getTypeAsString() const {
    switch (type) {
        case PokemonType::FIRE: return "Fire";
        case PokemonType::GRASS: return "Grass";
        case PokemonType::WATER: return "Water";
        case PokemonType::ELECTRIC: return "Electric";
        default: return "Unknown";
    }
}

