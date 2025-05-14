#include "pthread.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "bits/stdc++.h"
#include "ctime"
#include "cstdlib"
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

float mem;

// Timer function
void displayTime() {
    int sec_prev = 0;

    while (true) {
        int seconds, minutes, hours;
        string str;

        // Storing total seconds
        time_t total_seconds = time(0);
        struct tm* ct = localtime(&total_seconds);

        seconds = ct->tm_sec;
        minutes = ct->tm_min;
        hours = ct->tm_hour;

        // Converting it into 12 hour format
        if (hours >= 12)
            str = "PM";
        else
            str = "AM";

        hours = hours > 12 ? hours - 12 : hours;

        // Printing the result
        system("clear");
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << " " << str << endl;

        sec_prev = seconds;
        sleep(1); // Sleep for 1 second

        // Check for exit condition
        if (cin.peek() == '\n') { // Check if user pressed Enter
            break;
        }
    }
}

int main() {
    cout << "Press Enter to stop the timer..." << endl;
    displayTime(); // Start the timer
    return 0; // Added return statement for clarity
}
