#include "ProfessorOak.hpp"

void ProfessorOak::greetPlayer(Player& player) {
    std::cout << "Professor Oak: Hello there! Welcome to the world of Pokémon!\n";
    std::cout << "Professor Oak: My name is " << name << ". People call me the Pokémon Professor!\n";
    std::cout << "Professor Oak: But enough about me. Let's talk about you!\n";
    std::cout << "Professor Oak: First, tell me, what's your name?\n";
    std::cin >> player.name;
    std::cout << "Professor Oak: Ah, " << player.name << "! What a fantastic name!\n";
    Utility::waitForEnter();
}

void ProfessorOak::offerPokemonChoices(Player& player) {
    std::cout << "Professor Oak: I have three Pokémon here with me. They're all quite feisty! \n";
    std::cout << "1. Charmander - The fire type. A real hothead!\n";
    std::cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
    std::cout << "3. Squirtle - The water type. Cool as a cucumber!\n";
    std::cout << "Choose your Pokémon by entering the number: ";
    
    int choice;
    std::cin >> choice;
    
    player.choosePokemon(static_cast<PokemonChoice>(choice));
    std::cout << "Professor Oak: " << player.chosenPokemon.name << " and you, " << player.name 
              << ", are going to be the best of friends!\n";
    std::cout << "Type: " << player.chosenPokemon.getTypeAsString() << "\n";
    std::cout << "Your journey begins now! Get ready to explore the vast world of Pokémon!\n";
    Utility::waitForEnter();
}

void ProfessorOak::explainMainQuest(Player& player) {
    std::cout << "Professor Oak: Ah, " << player.name << ", let me tell you about your grand adventure that's about to unfold!\n";
    std::cout << "Professor Oak: Becoming a Pokémon Master is no easy task. It demands courage, strategy, and sometimes a little bit of luck.\n";
    std::cout << "Professor Oak: Your main mission is to collect all the Pokémon Badges and defeat the Pokémon League.\n";
    std::cout << player.name << ": Wait, isn't that just like every other Pokémon game?\n";
    Utility::waitForEnter();
    std::cout << "Professor Oak: No breaking the fourth wall, " << player.name << "! This is serious business.\n";
    std::cout << "Professor Oak: So, are you ready to embark on this epic journey?\n";
    Utility::waitForEnter();
    std::cout << player.name << ": Ready as I'll ever be, Professor!\n";
    std::cout << "Professor Oak: That's the spirit! Now, your journey begins.\n";
}