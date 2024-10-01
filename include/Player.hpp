#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include "Utility.hpp"
#include "Pokemon.hpp"

class Pokemon;
class Player {
public:
    std::string name;
    Pokemon* chosenPokemon; // Changed from Pokemon to Pokemon*

    Player();
    Player(std::string p_name, Pokemon* p_chosenPokemon);
    Player(const Player& other);
    ~Player(); // Destructor to handle dynamic memory

    void choosePokemon(PokemonChoice choice);
};

#endif