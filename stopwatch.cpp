#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

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
        cout << "Elapsed time (in seconds): " << stopwatch.elapsed_seconds() << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    cout << "\t\tWELCOME TO STOPWATCH PROCESS!" << endl;

    Stopwatch stopwatch;
    atomic<bool> running(true);

    cout << "Stopwatch started. Press Enter to stop." << endl;

    // Start displaying elapsed time in a separate thread
    thread display_thread(display_elapsed_time, ref(running), ref(stopwatch));

    // Wait for user to press Enter
    cin.get();

    running.store(false); // Stop the thread
    display_thread.join(); // Wait for the thread to finish

    cout << "Stopwatch stopped. Final elapsed time (in seconds): " << stopwatch.elapsed_seconds() << endl;

    return 0;
}
