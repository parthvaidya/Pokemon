#include "BattleManager.hpp"
#include "BattleState.hpp"
#include "Pikachu.hpp"
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
    cout << "A wild " << wildPokemon.name << " appears!\n";
    Utility::waitForEnter();

    // Initialize battle participants
    Pokemon& playerPokemon = player.chosenPokemon;
    
    // Explicitly initialize enemyPokemon using WildPokemon's attributes
    Pokemon enemyPokemon(wildPokemon.name, wildPokemon.type, wildPokemon.health);

    cout << player.name << "'s " << playerPokemon.name << " vs. Wild " << enemyPokemon.name << "!\n";
    Utility::waitForEnter();

    // Battle loop
    while (true) {
        // Player's turn to attack
        cout << "\nYour turn!\n";

        // Pikachu* pikachu = dynamic_cast<Pikachu*>(&playerPokemon);
        // if (pikachu) {
        //     pikachu->thunderShock(enemyPokemon);
        // } else {
        //     playerPokemon.attack(enemyPokemon);
        // }



        playerPokemon.attack(enemyPokemon);

        if (enemyPokemon.isFainted()) {
            cout << "Wild " << enemyPokemon.name << " has fainted! You won the battle!\n";
            break;
        }

        // Wild Pokémon's turn to attack
        cout << "\nWild " << enemyPokemon.name << "'s turn!\n";
        enemyPokemon.attack(playerPokemon);

        if (playerPokemon.isFainted()) {
            cout << playerPokemon.name << " has fainted! You lost the battle...\n";
            // Optionally, handle the player's loss here (e.g., reduce items, restart game loop)
            break;
        }

        // Display current health status
        cout << "\nCurrent Health:\n";
        cout << playerPokemon.name << ": " << playerPokemon.health << "/" << playerPokemon.maxHealth << "\n";
        cout << enemyPokemon.name << ": " << enemyPokemon.health << "/" << enemyPokemon.maxHealth << "\n";

        Utility::waitForEnter();
    }

    // Reset wild Pokémon's health after battle
    wildPokemon.health = enemyPokemon.maxHealth;
}

void BattleManager::handleBattleOutcome(Player& player, bool playerWon) {
    if (playerWon) {
        cout << "You won the battle!\n";
    } else {
        cout << player.chosenPokemon.name << " has fainted! You lost the battle...\n";
        // Optionally handle player loss here
    }
}



