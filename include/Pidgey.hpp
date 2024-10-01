#ifndef PIDGEY_HPP
#define PIDGEY_HPP
#include "Pokemon.hpp"
#include "Move.hpp"
#include <string>
#include <iostream>

class Pidgey {
public:
    std::string name;
    int health;
    Move move;

    Pidgey() : name("Pidgey"), health(45), move("Gust", 25) {}

    void attack(Pidgey& target) {
        target.health -= move.power;
        std::cout << name << " used " << move.name << "!\n";
    }
};
#endif