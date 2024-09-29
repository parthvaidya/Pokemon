#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <memory>
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

    virtual ~Pokemon() = default;

    // Clone method for polymorphic copying
    virtual std::unique_ptr<Pokemon> clone() const = 0;

    std::string getTypeAsString() const;
    void takeDamage(int damage);
    bool isFainted() const;
    void attack(Pokemon& target);

};

#endif