#ifndef ZUBAT_HPP
#define ZUBAT_HPP
#include "Pokemon.hpp"
#include "Move.hpp"  // Include the Move header
#include <string>

class Zubat : public Pokemon {
public:
    Zubat(std::string p_name, int p_health, Move p_move);

    // Method for Zubat's special attack
    void supersonic(Pokemon& target);

private:
    int supersonicDamage;
    Move move;
};
#endif