#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include "PokemonType.hpp"

enum class PokemonType;

class Pokemon {
public:
    std::string name;
    PokemonType type;
    int health;
    int maxHealth;
    Pokemon();
    Pokemon(std::string p_name, PokemonType p_type, int p_health);
    Pokemon(const Pokemon& other);

    std::string getTypeAsString() const;
    void takeDamage(int damage);
    bool isFainted() const;
    void attack(Pokemon& target);
    // virtual void attack(Pokemon& target) = 0;
};

#endif