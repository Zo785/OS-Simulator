#include <iostream>
#include <cstdio>    // For rename()
#include <cstdlib>   // For system()
#include <cstring>   // For strerror()
#include <cerrno>    // For errno
#include <unistd.h>  // For access()

using namespace std;

// Function to move or rename a file
bool moveOrRenameFile(const string& oldPath, const string& newPath) {
    // Check if the old file exists
    if (access(oldPath.c_str(), F_OK) != 0) {
        cerr << "Error: File not found at " << oldPath << endl;
        return false;
    }

    // Attempt to rename (which also moves if the new path is different)
    if (rename(oldPath.c_str(), newPath.c_str()) == 0) {
        cout << "File successfully moved/renamed from " << oldPath << " to " << newPath << endl;
        return true;
    } else {
        cerr << "Error moving/renaming file: " << strerror(errno) << endl;
        return false;
    }
}

int main() {
    string oldPath, newPath;

    cout << "Enter the full path of the file to move/rename: ";
    getline(cin, oldPath);
    cout << "Enter the new path (directory or new file name): ";
    getline(cin, newPath);

    moveOrRenameFile(oldPath, newPath);

    return 0;
}
