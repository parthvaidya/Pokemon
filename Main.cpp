#include <iostream>
using namespace std;

int main() {

    string player_name;

    //  Greet the Player
    cout << "Professor Oak: \n";
    cout << "\"Ah, Trainer! Welcome to the world of Pokémon!\"\n";
    cout << "\"Today is a momentous day—youll be choosing your very first Pokémon.\"\n";
    cout << "\"Every great Trainer remembers this moment for the rest of their lives.\"\n";
    cout << "\"So, choose wisely, young one!\"\n\n";

    cout << "Professor Oak: First, tell me, whats your name?\n";
    cin >> player_name;

    cout << "Professor Oak: Ah, " << player_name << "! What a fantastic name!\n";
    cout << "Professor Oak: You must be eager to start your adventure. But "
                "first, youll need a Pokemon of your own!\n";

    //  Display the Pokémon Choices
    cout << "Choose your Pokémon:\n";
    cout << "1. Bulbasaur\n";
    cout << "2. Charmander\n";
    cout << "3. Squirtle\n";

    // Capture the Player’s Choice
    int choice;
    cout << "Enter the number of your choice: ";
    cin >> choice;

    // Step 4: Confirm the Choice
   
    switch (choice) {
        case 1:
            cout << "Professor Oak: A fine choice! Bulbasaur is always ready to grow on you!\n";
            break;
        case 2:
            cout << "Professor Oak: A fiery choice! Charmander is yours!\n";
            break;
        case 3:
            cout << "Professor Oak: Splendid! Squirtle will keep you cool under pressure!\n";
            break;
        default:
            // Step 2: Surprise with Pikachu for an Invalid Choice
            cout << "Professor Oak: Hmm, that doesn't seem right. Let me choose for you… Just kidding! Let's go with Pikachu, the surprise guest!\n";
            break;
    }

    cout << "\nProfessor Oak: \n";
    cout << "\"Ah, an excellent choice! But beware " << player_name << ", this is only the beginning.\"\n";
    cout << "\"Your journey is about to unfold. Now let’s see if you have what it takes to keep going!\"\n";
    cout << "\"Good luck, and remember… Choose wisely!\"\n";

    return 0;
}