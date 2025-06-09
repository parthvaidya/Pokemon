#ifndef PROFESSOROAK_HPP
#define PROFESSOROAK_HPP

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Utility.hpp"

class ProfessorOak {
public:
    std::string name;

    void greetPlayer(Player& player);
    void offerPokemonChoices(Player& player);
    void explainMainQuest(Player& player);
};

#endif