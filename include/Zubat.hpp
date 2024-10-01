#ifndef ZUBAT_HPP
#define ZUBAT_HPP
#include "Pokemon.hpp"

class Zubat : public Pokemon {
public:
    Zubat(std::string p_name, int p_health, int p_supersonicDamage);

    // Method for Zubat's special attack
    // void supersonic(Pokemon& target);
    void attack(Pokemon& target) override;

private:
    int supersonicDamage;
};
#endif