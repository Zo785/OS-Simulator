#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h> // Include pthread header

using namespace std;

float mem = 2.0; // Initialize memory
int temp;

// Timer function
void displayTime() {
    int sec_prev = 0;
    while (true) {
        time_t total_seconds = time(0);
        struct tm* ct = localtime(&total_seconds);

        int seconds = ct->tm_sec;
        int minutes = ct->tm_min;
        int hours = ct->tm_hour;

        string str = (hours >= 12) ? "PM" : "AM";
        hours = (hours > 12) ? hours - 12 : hours;

        if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0)) {
            system("clear");
            cout << (hours < 10 ? "0" : "") << hours << ":"
                 << (minutes < 10 ? "0" : "") << minutes << ":"
                 << (seconds < 10 ? "0" : "") << seconds << " " << str << endl;
            break;
        }
        sec_prev = seconds;
    }
}

// Display memory function
void displayMemory(float n) {
    displayTime();
    
    cout << "\n\t------------------------\n\tMaking file has taken RAM: " << n << " GB" << endl;
    cout << "Remaining RAM = " << mem << " GB" << endl;
    cout << "\n\t------------------------\n\n";
}

// Make file function
void* makefile(void* args) {
    string filename = *(std::string*)args;
    fstream file;
    file.open(filename, std::ios::out | std::ios::app);

    if (file.fail() || file.bad()) {
        cout << "Error in creating file " << filename << "!!!" << endl;
    } else {
        cout << "File " << filename << " created successfully." << endl;
    }

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <some_integer>" << endl;
        return 1; // Exit if no argument is provided
    }

    temp = stoi(argv[1]);
    pthread_t T1;
    int n = 0;
    string f;

    system("clear");
    cout << "\n\n\n\t LOADING...." << endl;
    sleep(3);
    system("clear");
    cout << "\t\t Welcome to MakeFile App  \t\t" << endl;
    sleep(5);
    system("clear");
    
    while (true) {
        displayMemory(2);
        cout << "1. To make new file" << endl;
        cout << "2. For exit" << endl;
        cin >> n;

        if (n == 1) {
            cout << "Enter Filename: ";
            cin >> f;
            pthread_create(&T1, NULL, &makefile, (void*)&f);
            pthread_join(T1, NULL);
        } else if (n == 2) {
            pthread_exit(NULL);
        }
    }
    return 0;
}

