#ifndef PIKACHU_HPP
#define PIKACHU_HPP
#include "Pokemon.hpp"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#pragma once

class Pikachu : public Pokemon {
private:
    int thunderShockDamage;

public:
    // Constructor
    Pikachu();

    // Unique attack method
    void thunderShock(Pokemon& target);

    // Override clone method
    virtual std::unique_ptr<Pokemon> clone() const override;
};


#endif