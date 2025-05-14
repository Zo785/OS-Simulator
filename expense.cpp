#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ExpenseTracker {
    vector<string> transactions;
    
public:
    void addTransaction(const string& transaction) {
        transactions.push_back(transaction);
    }

    void viewTransactions() {
        cout << "Transactions:\n";
        for (const auto& t : transactions) {
            cout << t << endl;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    string transaction;
    int choice;

    while (true) {
        cout << "1. Add Transaction\n2. View Transactions\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter transaction (e.g., Income: $100 or Expense: $50): ";
            cin.ignore();
            getline(cin, transaction);
            tracker.addTransaction(transaction);
        } else if (choice == 2) {
            tracker.viewTransactions();
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
