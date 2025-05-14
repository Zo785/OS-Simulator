#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guess_game() {
    int num, guess, tries = 0;
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    num = rand() % 10 + 1; // Random number between 1 and 10

    cout << "🎉 Welcome to the Guessing Game! 🎉\n";
    cout << "🤔 Guess a number between 1 and 10! 🤔\n";

    do {
        cout << "Your guess: ";
        cin >> guess;
        tries++;

        if (guess > num) {
            cout << "🔴 Too high! Try again!\n\n";
        } else if (guess < num) {
            cout << "🔵 Too low! Try again!\n\n";
        } else {
            cout << "✅ Correct! You got it in " << tries << " guesses! 🎊\n";
        }
    } while (guess != num);
}

int main() {
    int choice;

    do {
        cout << "Press 1 to play the Guessing Game 🎮\n";
        cout << "Press 0 to exit 🚪\n";
        cin >> choice;

        if (choice == 1) {
            guess_game();
        } else if (choice == 0) {
            cout << "Thanks for playing! Goodbye! 👋\n";
        } else {
            cout << "🚫 Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
