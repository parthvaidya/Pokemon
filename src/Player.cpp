#include "Player.hpp"
#include "Utility.hpp"
#include "Pikachu.hpp"
#include <memory>
#include <iostream>

Player::Player() : name("Trainer"), chosenPokemon() {}

Player::Player(std::string p_name, std::unique_ptr<Pokemon> p_chosenPokemon)
    : name(p_name), chosenPokemon(std::move(p_chosenPokemon)) {}

Player::Player(const Player& other)
    : name(other.name), chosenPokemon(other.chosenPokemon->clone()) {}

// Player& Player::operator=(const Player& other) {
//     if (this == &other)
//         return *this;
//     name = other.name;
//     if (other.chosenPokemon)
//         chosenPokemon = other.chosenPokemon->clone();
//     else
//         chosenPokemon = nullptr;
//     return *this;
// }

void Player::choosePokemon(PokemonChoice choice) {
    switch (choice) {
        // case PokemonChoice::Pidgey:
        //     chosenPokemon = std::make_unique<Pidgey>();
        //     std::cout << "You chose Pidgey!\n";
        //     break;
        // case PokemonChoice::Caterpie:
        //     chosenPokemon = std::make_unique<Caterpie>();
        //     std::cout << "You chose Caterpie!\n";
        //     break;
        // case PokemonChoice::Zubat:
        //     chosenPokemon = std::make_unique<Zubat>();
        //     std::cout << "You chose Zubat!\n";
            // break;
        case PokemonChoice::Pikachu:
            chosenPokemon = std::make_unique<Pikachu>();
            std::cout << "You chose Pikachu!\n";
            break;
        default:
            chosenPokemon = std::make_unique<Pikachu>();
            std::cout << "Pikachu is the default choice.\n";
            break;
    }
}