#ifndef PARALYZEDEFFECT_HPP
#define PARALYZEDEFFECT_HPP

#include "IStatusEffect.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <cstdlib>  // For random number generation
#include <ctime>    // For seeding the random number generator

class ParalyzedEffect : public IStatusEffect {
public:
    ParalyzedEffect();  // Constructor to initialize the number of turns
    void applyEffect(Pokemon& target) override;
    std::string getEffectName() const override;
    bool turnEndEffect(Pokemon& target) override;
    // void clearEffect(Pokemon& target) override;

private:
    int turnsLeft;  // Tracks how many turns the paralysis effect will last
};

#endif