#ifndef BATTLE_STATE_HPP
#define BATTLE_STATE_HPP

#include "Pokemon.hpp" // Ensure Pokemon class is included

struct BattleState {
    Pokemon* playerPokemon;
    Pokemon* wildPokemon;
    bool playerTurn;
    bool battleOngoing;

    BattleState(Pokemon* playerPoke, Pokemon* wildPoke)
        : playerPokemon(playerPoke), wildPokemon(wildPoke), playerTurn(true), battleOngoing(true) {}
};

#endif