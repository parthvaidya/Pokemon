#ifndef CATERPIE_HPP
#define CATERPIE_HPP
#include "Pokemon.hpp"

#include "Move.hpp"
#include <string>
#include <iostream>

class Caterpie : public Pokemon {
public:
    // Constructor
    Caterpie(std::string p_name, int p_health, int p_bugBiteDamage);

    // Method for Bug Bite attack
    void bugBite(Pokemon& target);

private:
    int bugBiteDamage;  // Variable to store the damage value for Bug Bite
};

#endif