#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>

struct Move {
    std::string name;
    int power;

    Move(std::string moveName, int movePower) 
        : name(moveName), power(movePower) {}
};

#endif // MOVE_HPP