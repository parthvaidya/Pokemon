#ifndef PIKACHU_HPP
#define PIKACHU_HPP
#include "Pokemon.hpp"

class Pikachu : public Pokemon {
private:
    int thunderShockDamage;  // Unique attack power for Thunder Shock

public:
    // Constructor
    Pikachu(std::string p_name = "Pikachu", int p_health = 35, int p_thunderShockDamage = 15);

    // Unique attack method
    void thunderShock(Pokemon& target);
    // void attack(Pokemon& target) override;
};
#endif