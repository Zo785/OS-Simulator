#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <sys/shm.h>
#include <cstdlib> // for exit()
using namespace std;

class Stopwatch {
public:
    Stopwatch() : start_time(std::chrono::high_resolution_clock::now()) {}

    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double elapsed_seconds() {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - start_time).count();
        return duration / 1e6;
    }

private:
    std::chrono::high_resolution_clock::time_point start_time;
};

void display_elapsed_time(std::atomic<bool>& running, Stopwatch& stopwatch) {
    while (running.load()) {
        system("clear"); // Clear screen for better display
        cout << "Elapsed time (in seconds): " << stopwatch.elapsed_seconds() << endl;
        cout << "Press Enter to stop..." << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Update more frequently
    }
}

int main() {
    // Initialize shared memory
    key_t key = ftok("stopwatch", 65); // Use a unique key
    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    int* shared_memory = (int*)shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Update shared memory
    *shared_memory -= 2; // Deduct RAM for this process

    system("clear");
    cout<<"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout << "\t\t\tWELCOME TO STOP WATCH PROCESS!"<<endl;
    cout<<"\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout << "\nStopwatch started. Press Enter to stop." << endl;

    Stopwatch stopwatch;
    atomic<bool> running(true);
    thread display_thread(display_elapsed_time, ref(running), ref(stopwatch));

    // Wait for user input
    cin.get();

    running = false;
    display_thread.join();

    system("clear");
    cout << "Stopwatch stopped. Final elapsed time: " 
         << stopwatch.elapsed_seconds() << " seconds" << endl;

    // Return RAM before exiting
    *shared_memory += 2;

    // Clean up shared memory
    shmdt(shared_memory);
    
    cout << "Press Enter to exit..." << endl;
    cin.get(); // Wait for user before closing

    return 0;
}
