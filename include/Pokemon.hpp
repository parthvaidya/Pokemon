#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <vector>
#include "PokemonType.hpp"
#include "Move.hpp"
#include "PokemonType.hpp"

enum class PokemonType;

class Pokemon {
public:
    std::string name;
    PokemonType type;
    int health;
    int maxHealth;
    std::vector<Move> moves; // Vector to hold Pokémon's moves

    Pokemon();
    Pokemon(std::string p_name, PokemonType p_type, int p_health);
    Pokemon(const Pokemon& other);
    virtual ~Pokemon() {} // Virtual destructor

    std::string getTypeAsString() const;
    void takeDamage(int damage);
    bool isFainted() const;

    virtual void attack(Pokemon& target) = 0; // Pure virtual function

    // New function to select and use a move
    Move selectAndUseMove(Pokemon& target);
};

#endif