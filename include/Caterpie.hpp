#ifndef CATERPIE_HPP
#define CATERPIE_HPP
#include "Pokemon.hpp"
#include "Move.hpp"  // Include the Move header
#include <string>
#include <iostream>

class Caterpie : public Pokemon {
public:
    Caterpie(std::string p_name, int p_health, Move p_move);

    // Method for Caterpie's special attack
    void bugBite(Pokemon& target);

private:
    int bugBiteDamage;
    Move move; 
};

#endif