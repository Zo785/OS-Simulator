#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string question;
    string answer;
};

int main() {
    vector<Question> quiz = {
        {"What is the capital of France?", "Paris"},
        {"What is 2 + 2?", "4"},
        {"What is the color of the sky?", "Blue"},
        {"What is the largest planet in our solar system?", "Jupiter"},
        {"Who wrote 'Romeo and Juliet'?", "Shakespeare"},
        {"What is the boiling point of water in Celsius?", "100"},
        {"What is the chemical symbol for gold?", "Au"},
        {"In which year did the Titanic sink?", "1912"},
        {"What is the currency of Japan?", "Yen"},
        {"Who painted the Mona Lisa?", "Da Vinci"}
    };

    int score = 0;

    for (const auto& q : quiz) {
        string userAnswer;
        cout << q.question << endl;
        cin >> userAnswer;

        if (userAnswer == q.answer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer is: " << q.answer << endl;
        }
    }

    cout << "Your score: " << score << "/" << quiz.size() << endl;
    return 0;
}

