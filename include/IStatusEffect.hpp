#ifndef ISTATUSEFFECT_HPP
#define ISTATUSEFFECT_HPP

#include "Pokemon.hpp"  // Assuming status effects apply to Pokemon objects

class IStatusEffect {
public:
    virtual ~IStatusEffect() = default;  // Virtual destructor for proper cleanup of derived classes

    
    virtual void applyEffect(Pokemon& target) = 0;

    
    virtual std::string getEffectName() const = 0;

    
    virtual bool turnEndEffect(Pokemon& target) = 0;

    // Method for clearing the status effect once it's over
    virtual void clearEffect(Pokemon& target) = 0;
};

#endif