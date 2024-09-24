#include <iostream>
using namespace std;

int main() {
    //  Greet the Player
    cout << "Professor Oak: \n";
    cout << "\"Ah, Trainer! Welcome to the world of Pokémon!\"\n";
    cout << "\"Today is a momentous day—you’ll be choosing your very first Pokémon.\"\n";
    cout << "\"Every great Trainer remembers this moment for the rest of their lives.\"\n";
    cout << "\"So, choose wisely, young one!\"\n\n";

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
    if (choice == 1) {
        cout << "You chose Bulbasaur! A wise choice.\n";
    } else if (choice == 2) {
        cout << "You chose Charmander! A fiery choice.\n";
    } else if (choice == 3) {
        cout << "You chose Squirtle! A cool choice.\n";
    } else {
        cout << "Invalid choice. Please restart the game.\n";
        exit(0);
    }

    cout << "\nProfessor Oak: \n";
    cout << "\"Ah, an excellent choice! But beware, Trainer, this is only the beginning.\"\n";
    cout << "\"Your journey is about to unfold. Now let’s see if you’ve got what it takes to keep going!\"\n";
    cout << "\"Good luck, and remember… Choose wisely!\"\n";

    return 0;
}