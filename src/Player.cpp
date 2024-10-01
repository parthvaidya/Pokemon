#include "Player.hpp"
#include "Utility.hpp"
#include "Pikachu.hpp"
#include "Zubat.hpp"
#include "Caterpie.hpp"
#include "Pidgey.hpp"
#include <iostream>

Player::Player() : name("Trainer"), chosenPokemon() {}

Player::Player(std::string p_name, Pokemon* p_chosenPokemon)
    : name(p_name), chosenPokemon(p_chosenPokemon) {}

Player::Player(const Player& other) 
    : name(other.name), chosenPokemon(other.chosenPokemon) {}


Player::Player(const Player& other)
    : name(other.name), chosenPokemon(nullptr) {
    if (other.chosenPokemon) {
        // Clone the chosenPokemon based on its actual type
        if (auto pikachu = dynamic_cast<Pikachu*>(other.chosenPokemon)) {
            chosenPokemon = new Pikachu(*pikachu);
        }
        
        else if (auto zubat = dynamic_cast<Zubat*>(other.chosenPokemon)) {
            chosenPokemon = new Zubat(*zubat);
        }
        else if (auto pidgey = dynamic_cast<Pidgey*>(other.chosenPokemon)) {
            chosenPokemon = new Pidgey(*pidgey);
        }
        else if (auto caterpie = dynamic_cast<Caterpie*>(other.chosenPokemon)) {
            chosenPokemon = new Caterpie(*caterpie);
        }
        else {
            std::cout << "Unknown Pokémon type during copy.\n";
        }
    }
}

// Destructor
Player::~Player() {
    if (chosenPokemon != nullptr) {
        delete chosenPokemon;
        chosenPokemon = nullptr;
    }
}

// Method to choose a Pokémon
void Player::choosePokemon(PokemonChoice choice) {
    // Delete existing Pokémon if any
    if (chosenPokemon != nullptr) {
        delete chosenPokemon;
        chosenPokemon = nullptr;
    }

    // Instantiate the chosen Pokémon based on the choice
    switch (choice) {
        
        case PokemonChoice::Pikachu:
            chosenPokemon = new Pikachu("Pikachu", 35, 15); // Example stats
            std::cout << "Pikachu is the best from the rest.\n";
            break;
        case PokemonChoice::Zubat:
            chosenPokemon = new Zubat("Zubat", 35, 10); // Example stats
            std::cout << "Zubat joins your team!\n";
            break;
        case PokemonChoice::Pidgey:
            chosenPokemon = new Pidgey("Pidgey", 40, 12); // Example stats
            std::cout << "Pidgey flutters onto your team!\n";
            break;
        case PokemonChoice::Caterpie:
            chosenPokemon = new Caterpie("Caterpie", 35, 8); // Example stats
            std::cout << "Caterpie crawls onto your team!\n";
            break;
        default:
            chosenPokemon = new Pikachu("Pikachu", 35, 15); // Default choice
            std::cout << "Pikachu is the best from the rest.\n";
            break;
    }
}