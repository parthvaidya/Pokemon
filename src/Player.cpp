#include "Player.hpp"
#include "Utility.hpp"
#include "Pikachu.hpp"
#include <iostream>

Player::Player() : name("Trainer"), chosenPokemon() {}

Player::Player(std::string p_name, Pokemon p_chosenPokemon) 
    : name(p_name), chosenPokemon(p_chosenPokemon) {}

Player::Player(const Player& other) 
    : name(other.name), chosenPokemon(other.chosenPokemon) {}


void Player::choosePokemon(PokemonChoice choice) {
    // Typecast choice to PokemonChoice enum
    switch (static_cast<PokemonChoice>(choice)) {
        case PokemonChoice::Charmander:
            chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 39);
            std::cout << "A fiery choice! Charmander is yours!\n";
            break;
        case PokemonChoice::Bulbasaur:
            chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 45);
            std::cout << "A fine choice! Bulbasaur is always ready to grow on you!\n";
            break;
        case PokemonChoice::Squirtle:
            chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 44);
            std::cout << "Splendid! Squirtle will keep you cool under pressure!\n";
            break;
        case PokemonChoice::Pikachu:
            chosenPokemon = Pikachu();  // Instantiate Pikachu
            std::cout << "Pikachu is the best from the rest.\n";
            break;
        default:
            chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 40);
            std::cout << "Pikachu is the best from the rest.\n";
            break;
    }
}