#include <iostream>
#include <string>
#include <cstdlib>
#include "PokemonType.hpp"
#include "Utility.hpp"
using namespace std;

enum class PokemonChoice {
    Charmander = 1,
    Bulbasaur,
    Squirtle,
    Pikachu 
};



class Pokemon {
public:
    string name;
    PokemonType type;
    int health;

    // Default constructor
    Pokemon() : name("Pikachu"), type(PokemonType::ELECTRIC), health(10) {}

    // Parameterized constructor
    Pokemon(string p_name, PokemonType p_type, int p_health) 
        : name(p_name), type(p_type), health(p_health) {}

    // Copy constructor
    Pokemon(const Pokemon& other) 
        : name(other.name), type(other.type), health(other.health) {}

    // Convert enum type to string for display purposes
    string getTypeAsString() const {
        switch (type) {
            case PokemonType::FIRE: return "Fire";
            case PokemonType::GRASS: return "Grass";
            case PokemonType::WATER: return "Water";
            case PokemonType::ELECTRIC: return "Electric";
            default: return "Unknown";
        }
    }
};

class Player {
public:
    string name;
    Pokemon chosenPokemon;

    // Default constructor
    Player() : name("Trainer"), chosenPokemon() {} // Calls the default constructor of Pokemon

    // Parameterized constructor
    Player(string p_name, Pokemon p_chosenPokemon) 
        : name(p_name), chosenPokemon(p_chosenPokemon) {}

    // Copy constructor
    Player(const Player& other) 
        : name(other.name), chosenPokemon(other.chosenPokemon) {}

    void choosePokemon(PokemonChoice choice) {
        switch (choice) {
            case PokemonChoice::Charmander:
                chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 39);
                cout << "A fiery choice! Charmander is yours!\n";
                break;
            case PokemonChoice::Bulbasaur:
                chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 45);
                cout << "A fine choice! Bulbasaur is always ready to grow on you!\n";
                break;
            case PokemonChoice::Squirtle:
                chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 44);
                cout << "Splendid! Squirtle will keep you cool under pressure!\n";
                break;
            default:
                chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 40);
                cout << "Pikachu is the best from the rest.\n";
                break;
        }
    }
};

class ProfessorOak {
public:
    string name;

    void greetPlayer(Player& player) {
        cout << "Professor Oak: Hello there! Welcome to the world of Pokémon!\n";
       
        cout << "Professor Oak: My name is " << name << ". People call me the Pokémon Professor!\n";
        
        cout << "Professor Oak: But enough about me. Let's talk about you!\n";
        
        cout << "Professor Oak: First, tell me, what's your name?\n";
        cin >> player.name;
        cout << "Professor Oak: Ah, " << player.name << "! What a fantastic name!\n";
        Utility::waitForEnter();
    }

    void offerPokemonChoices(Player& player) {
        cout << "Professor Oak: I have three Pokemon here with me. They're all quite feisty! \n";
        cout << "1. Charmander - The fire type. A real hothead!\n";
        cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
        cout << "3. Squirtle - The water type. Cool as a cucumber!\n";
        cout << "Choose your Pokémon by entering the number: ";
        
        int choice;
        cin >> choice;
        
        player.choosePokemon(static_cast<PokemonChoice>(choice));
        cout << "Professor Oak: " << player.chosenPokemon.name << " and you, " << player.name 
             << ", are going to be the best of friends!\n";
        cout << "Type: " << player.chosenPokemon.getTypeAsString() << "\n";
        cout << "Your journey begins now! Get ready to explore the vast world of Pokemon!\n";
        Utility::waitForEnter();
    }

    void explainMainQuest(Player& player) {
        cout << "Professor Oak: Ah, " << player.name << ", let me tell you about your grand adventure that's about to unfold!\n";
        
        cout << "Professor Oak: Becoming a Pokémon Master is no easy task. It demands courage, strategy, and sometimes a little bit of luck.\n";
        
        cout << "Professor Oak: Your main mission is to collect all the Pokémon Badges and defeat the Pokémon League. Only then can you challenge the Elite Four and aim for the title of Champion.\n";
        
        cout << player.name << ": Wait, isnt that just like every other Pokémon game?\n";
        Utility::waitForEnter();
        cout << "Professor Oak: No breaking the fourth wall, " << player.name << "! This is serious business.\n";
       
        cout << "Professor Oak: To achieve this, you must capture new Pokémon, battle wild creatures, challenge gym leaders, and keep your Pokémon healthy at the PokeCenter.\n";
        
        cout << "Professor Oak: Remember, you can only carry a limited number of Pokémon. Choose wisely who you want on your team!\n";
        
        cout << player.name << ": Piece of cake, right?\n";
       Utility::waitForEnter();
        cout << "Professor Oak: Ha! Thats what everyone thinks. But the path to becoming a Champion is filled with obstacles. Lose a battle, and it’s back to the start!\n";
        
        cout << "Professor Oak: So, what do you say? Are you ready to embark on this epic journey to become the next Pokémon Champion?\n";
       Utility::waitForEnter();
        cout << player.name << ": Ready as Ill ever be, Professor!\n";
        
        cout << "Professor Oak: Thats the spirit! Now, your journey begins. Remember, its not just about battling—its about forming bonds with your Pokémon. Go, Trainer, the world of Pokémon awaits you!\n";
       
        cout << "Professor Oak: Oh, and about the actual game loop… lets just pretend I didnt forget to set it up. Onwards!\n";
    }

    // Function to pause execution and wait for Enter key
    

};

void gameLoop(Player& player) {
    bool keepPlaying = true;

    while (keepPlaying) {
        int choice;
        cout << "What would you like to do next - " << player.name << "?\n";
        cout << "1. Battle Wild Pokémon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokémon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Utility::clearInputBuffer(); 
        switch (choice) {
            case 1:
                cout << "You look around... but all the wild Pokemon are on vacation. Maybe try again later?\n";
                break;
            case 2:
                cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokemon will have to tough it out for now!\n";
                break;
            case 3:
                cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
                break;
            case 4:
                cout << "You boldly step towards the Pokemon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
                break;
            case 5:
                cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokemon training!'\n";
                keepPlaying = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        
        if (keepPlaying) {
            ProfessorOak professor;
            Utility::waitForEnter();
        }
    }
}



int main() {
    Player player;
    ProfessorOak professor;
    professor.name = "Professor Oak";
    
    // Professor Oak greets the player and offers Pokémon choices
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
    Utility::clearConsole(); // Clear the console before explaining the main quest
    professor.explainMainQuest(player);

    // Print the name of the player and the name of the Pokémon they chose
    cout << player.name << " chose " << player.chosenPokemon.name << "!\n";
    cout << "Pokemon Type: " << player.chosenPokemon.getTypeAsString() << "\n";
    cout << "Pokemon Type: " << player.chosenPokemon.getTypeAsString() << "\n";


    gameLoop(player);
    return 0;
}
