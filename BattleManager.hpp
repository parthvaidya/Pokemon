// BattleManager.hpp
#ifndef BATTLES_MANAGER_HPP
#define BATTLES_MANAGER_HPP

#include "Player.hpp"
#include "grass.hpp" // Make sure to include the header for WildPokemon

class BattleManager {
public:
    
    void battle(Player& player, WildPokemon& wildPokemon);
    void handleBattleOutcome(Player& player, bool playerWon);
};

#endif // BATTLE_MANAGER_HPP