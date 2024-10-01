#ifndef ZUBAT_HPP
#define ZUBAT_HPP
#include "Pokemon.hpp"
#include "Move.hpp"
#include <string>
#include <iostream>
class Zubat {
public:
    std::string name;
    int health;
    Move move;

    Zubat() : name("Zubat"), health(40), move("Leech Life", 15) {}

    void attack(Zubat& target) {
        target.health -= move.power;
        std::cout << name << " used " << move.name << "!\n";
    }
};

#endif