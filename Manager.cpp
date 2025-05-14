#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void listFiles(const string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << entry.path() << endl;
    }
}

void createFile(const string& filename) {
    ofstream file(filename);
    if (file) {
        cout << "File created: " << filename << endl;
    } else {
        cout << "Error creating file." << endl;
    }
}

void deleteFile(const string& filename) {
    if (fs::remove(filename)) {
        cout << "File deleted: " << filename << endl;
    } else {
        cout << "Error deleting file." << endl;
    }
}

int main() {
    string path = ".";
    int choice;
    string filename;

    while (true) {
        cout << "1. List files\n2. Create file\n3. Delete file\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                listFiles(path);
                break;
            case 2:
                cout << "Enter filename: ";
                cin >> filename;
                createFile(filename);
                break;
            case 3:
                cout << "Enter filename to delete: ";
                cin >> filename;
                deleteFile(filename);
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}

