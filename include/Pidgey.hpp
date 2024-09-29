#ifndef PIDGEY_HPP
#define PIDGEY_HPP
#include "Pokemon.hpp"

class Pidgey : public Pokemon {
public:
    Pidgey(std::string p_name, int p_health, int p_wingAttackDamage);

    // Method for Pidgey's special attack
    void wingAttack(Pokemon& target);

private:
    int wingAttackDamage;
};
#endif