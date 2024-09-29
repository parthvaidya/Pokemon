#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include <memory>
#include "Utility.hpp"
#include "Pokemon.hpp"

class Pokemon;
class Player {
public:
    std::string name;
    std::unique_ptr<Pokemon> chosenPokemon;

    Player();
     Player(std::string p_name, std::unique_ptr<Pokemon> p_chosenPokemon);
    Player(const Player& other);

    void choosePokemon(PokemonChoice choice);
};

#endif