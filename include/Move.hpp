#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>

struct Move {
    std::string name;
    int power;

    Move(const std::string& moveName = "", int movePower = 0)
        : name(moveName), power(movePower) {}
};

#endif // MOVE_HPP
