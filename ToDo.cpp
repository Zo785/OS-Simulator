#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void viewTasks() {
        cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void deleteTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted.\n";
        } else {
            cout << "Invalid index.\n";
        }
    }
};

int main() {
    TodoList todo;
    int choice;
    string task;

    while (true) {
        cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                todo.addTask(task);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                int index;
                cout << "Enter task number to delete: ";
                cin >> index;
                todo.deleteTask(index);
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
