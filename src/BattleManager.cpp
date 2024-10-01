#include "BattleManager.hpp"
#include "BattleState.hpp"
#include "Pikachu.hpp"
#include "Zubat.hpp"
#include "Pidgey.hpp"
#include "Caterpie.hpp"
#include "Utility.hpp"
#include <iostream>
using namespace std;

BattleManager::BattleManager() : battleState(nullptr) {}

// Destructor
BattleManager::~BattleManager() {
    if (battleState != nullptr) {
        delete battleState;
    }
}

void BattleManager::battle(Player& player, WildPokemon& wildPokemon) {
    std::cout << "A wild " << wildPokemon.name << " appears!\n";
    Utility::waitForEnter();

    // Initialize battle participants
    Pokemon* playerPokemon = player.chosenPokemon; // Pointer to player's Pokémon

    // Instantiate the wild Pokémon based on its name
    Pokemon* enemyPokemon = nullptr;

    if (wildPokemon.name == "Zubat") {
        enemyPokemon = new Zubat(wildPokemon.name, wildPokemon.health, wildPokemon.type);
    }
    else if (wildPokemon.name == "Pidgey") {
        enemyPokemon = new Pidgey(wildPokemon.name, wildPokemon.type, wildPokemon.health);
    }
    else if (wildPokemon.name == "Caterpie") {
        enemyPokemon = new Caterpie(wildPokemon.name, wildPokemon.type, wildPokemon.health);
    }
    else if (wildPokemon.name == "Pikachu") {
        enemyPokemon = new Pikachu(wildPokemon.name, wildPokemon.type, wildPokemon.health);
    }
    else {
        std::cout << "Encountered an unknown Pokémon type: " << wildPokemon.name << ". The battle cannot proceed.\n";
        return;
    }

    std::cout << player.name << "'s " << playerPokemon->name << " vs. Wild " << enemyPokemon->name << "!\n";
    Utility::waitForEnter();

    // Battle loop
    while (true) {
        // Player's turn to attack
        std::cout << "\nYour turn!\n";

        playerPokemon->attack(*enemyPokemon);

        if (enemyPokemon->isFainted()) {
            std::cout << "Wild " << enemyPokemon->name << " has fainted! You won the battle!\n";
            break;
        }

        // Wild Pokémon's turn to attack
        std::cout << "\nWild " << enemyPokemon->name << "'s turn!\n";
        enemyPokemon->attack(*playerPokemon);

        if (playerPokemon->isFainted()) {
            std::cout << playerPokemon->name << " has fainted! You lost the battle...\n";
            // Optionally, handle the player's loss here (e.g., reduce items, restart game loop)
            break;
        }

        // Display current health status
        std::cout << "\nCurrent Health:\n";
        std::cout << playerPokemon->name << ": " << playerPokemon->health << "/" << playerPokemon->maxHealth << "\n";
        std::cout << enemyPokemon->name << ": " << enemyPokemon->health << "/" << enemyPokemon->maxHealth << "\n";

        Utility::waitForEnter();
    }

    // Reset wild Pokémon's health after battle
    wildPokemon.health = enemyPokemon->maxHealth;

    // Clean up enemy Pokémon
    delete enemyPokemon;
}

void BattleManager::handleBattleOutcome(Player& player, bool playerWon) {
    if (playerWon) {
        std::cout << "You won the battle!\n";
    }
    else {
        std::cout << player.chosenPokemon->name << " has fainted! You lost the battle...\n";
        // Optionally handle player loss here
    }
}


