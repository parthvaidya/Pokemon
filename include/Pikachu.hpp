#ifndef PIKACHU_HPP
#define PIKACHU_HPP
#include "Pokemon.hpp"
#include "Move.hpp"
#include <string>
#include <iostream>
class Pikachu {
public:
    std::string name;
    int health;
    Move move;

    Pikachu() : name("Pikachu"), health(35), move("Thunder Shock", 40) {}

    void attack(Pikachu& target) {
        target.health -= move.power;
        std::cout << name << " used " << move.name << "!\n";
    }
};
#endif