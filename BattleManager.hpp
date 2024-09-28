// BattleManager.hpp
#ifndef BATTLES_MANAGER_HPP
#define BATTLES_MANAGER_HPP

#include "Player.hpp"
#include "grass.hpp" 
#include "BattleState.hpp"

class BattleManager {
public:
    BattleManager();                                // Constructor
    ~BattleManager();                               // Destructor

    void battle(Player& player, WildPokemon& wildPokemon);
    void handleBattleOutcome(Player& player, bool playerWon);

private:
    BattleState* battleState;                       // Pointer to BattleState

    void startBattle(Player& player, WildPokemon& wildPokemon);
    void updateBattleState(Player& player);
};

#endif // BATTLE_MANAGER_HPP