#ifndef PIDGEY_HPP
#define PIDGEY_HPP
#include "Pokemon.hpp"
#include "Move.hpp"  // Include the Move header
#include <string>

class Pidgey : public Pokemon {
public:
     Pidgey(std::string p_name, int p_health, Move p_move); 

    // Method for Pidgey's special attack
    void wingAttack(Pokemon& target);

private: 
    int wingAttackDamage;
    Move move; 
};
#endif