#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void play_rps() {
    string choices[3] = {"Rock", "Paper", "Scissors"};
    int user_choice, computer_choice;
    
    cout << "👊 Rock, Paper, Scissors! ✋\n";
    cout << "Choose:\n1. Rock\n2. Paper\n3. Scissors\n";
    cin >> user_choice;
    
    // Random choice for computer
    srand(static_cast<unsigned int>(time(0)));
    computer_choice = rand() % 3 + 1;

    cout << "You chose: " << choices[user_choice - 1] << "\n";
    cout << "Computer chose: " << choices[computer_choice - 1] << "\n";

    if (user_choice == computer_choice) {
        cout << "🤝 It's a tie!\n";
    } else if ((user_choice == 1 && computer_choice == 3) || 
               (user_choice == 2 && computer_choice == 1) || 
               (user_choice == 3 && computer_choice == 2)) {
        cout << "🎉 You win!\n";
    } else {
        cout << "😢 You lose!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "Press 1 to play Rock-Paper-Scissors 🎮\n";
        cout << "Press 0 to exit 🚪\n";
        cin >> choice;

        if (choice == 1) {
            play_rps();
        } else if (choice == 0) {
            cout << "Thanks for playing! Goodbye! 👋\n";
        } else {
            cout << "🚫 Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
