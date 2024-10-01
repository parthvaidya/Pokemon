#ifndef CATERPIE_HPP
#define CATERPIE_HPP
#include "Pokemon.hpp"

class Caterpie : public Pokemon {
public:
    Caterpie(std::string p_name, int p_health, int p_bugBiteDamage);

    // Method for Caterpie's special attack
    // void bugBite(Pokemon& target);

    void attack(Pokemon& target) override;

private:
    int bugBiteDamage;
};

#endif