#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include "PokemonType.hpp"
#include <iostream>

enum class PokemonType;

class Pokemon {
public:
    string name;
    PokemonType type;
    int health;
    int maxHealth;
    Pokemon();
    Pokemon(string p_name, PokemonType p_type, int p_health);
    Pokemon(const Pokemon& other);

    string getTypeAsString() const;
    void takeDamage(int damage);
    bool isFainted() const;
    void attack(Pokemon& target);

};

#endif