#include <iostream>
#include <string>
#include <cstdlib>

#include "PokemonChoice.hpp"
#include "Player.hpp"
#include "Utility.hpp"
#include "grass.hpp"  
#include "WildEncounterManager.hpp"
#include "BattleManager.hpp"
using namespace std;


Grass forestGrass = {
    "Forest",
    {{"Pidgey", PokemonType::NORMAL, 40}, {"Caterpie", PokemonType::BUG, 35}},
    70
};

Grass caveGrass = {
    "Cave",
    {{"Zubat", PokemonType::NORMAL, 35}, {"Charlizard", PokemonType::FIRE, 50}},
    85
};

enum class PokemonType;

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
void battle(Player& player, WildPokemon& wildPokemon) {
    cout << "A wild " << wildPokemon.name << " appears!\n";
    Utility::waitForEnter();

    // Initialize battle participants
    Pokemon& playerPokemon = player.chosenPokemon;
    
    // Explicitly initialize enemyPokemon using WildPokemon's attributes
    Pokemon enemyPokemon(wildPokemon.name, wildPokemon.type, wildPokemon.health);

    cout << player.name << "'s " << playerPokemon.name << " vs. Wild " << enemyPokemon.name << "!\n";
    Utility::waitForEnter();

    // Battle loop
    while (true) {
        // Player's turn to attack
        cout << "\nYour turn!\n";
        playerPokemon.attack(enemyPokemon);

        if (enemyPokemon.isFainted()) {
            cout << "Wild " << enemyPokemon.name << " has fainted! You won the battle!\n";
            break;
        }

        // Wild Pokémon's turn to attack
        cout << "\nWild " << enemyPokemon.name << "'s turn!\n";
        enemyPokemon.attack(playerPokemon);

        if (playerPokemon.isFainted()) {
            cout << playerPokemon.name << " has fainted! You lost the battle...\n";
            // Optionally, handle the player's loss here (e.g., reduce items, restart game loop)
            break;
        }

        // Display current health status
        cout << "\nCurrent Health:\n";
        cout << playerPokemon.name << ": " << playerPokemon.health << "/" << playerPokemon.maxHealth << "\n";
        cout << enemyPokemon.name << ": " << enemyPokemon.health << "/" << enemyPokemon.maxHealth << "\n";

        Utility::waitForEnter();
    }

    // Reset wild Pokémon's health after battle
    wildPokemon.health = enemyPokemon.maxHealth;
}


void gameLoop(Player& player) {
    bool keepPlaying = true;
    WildEncounterManager encounterManager;  // Create an encounter manager
    BattleManager battleManager;

    WildPokemon encounteredPokemon{"", PokemonType::NORMAL, 0}; 

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
                
                encounteredPokemon = encounterManager.getRandomPokemonFromGrass(forestGrass);
                cout << "You encountered a wild " << encounteredPokemon.name << "!\n";
                Utility::waitForEnter();

                // Start the battle
                // battle(player, encounteredPokemon);
                 battleManager.battle(player, encounteredPokemon);
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

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
    Utility::clearConsole(); //clear console
    professor.explainMainQuest(player);

    cout << player.name << " chose " << player.chosenPokemon.name << "!\n";
    cout << "Pokemon Type: " << player.chosenPokemon.getTypeAsString() << "\n";

    gameLoop(player);
    
    return 0;
}
