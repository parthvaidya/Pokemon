#ifndef PIKACHU_HPP
#define PIKACHU_HPP
#include "Pokemon.hpp"
#include "Move.hpp"  // Include the Move header
#include <string>

class Pikachu : public Pokemon {
private:
    int thunderShockDamage;  // Unique attack power for Thunder Shock
    Move move; 
public:
    // Constructor
    Pikachu(std::string p_name, int p_health, Move p_move); 

    // Unique attack method
    void thunderShock(Pokemon& target);
    // void attack(Pokemon& target) override;
};
#endif