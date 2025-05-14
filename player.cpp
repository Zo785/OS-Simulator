#include <SDL.h>
#include <iostream>

using namespace std;

void playMusic(const char* filename) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return;
    }

    // Load and play music here (this is a placeholder)
    cout << "Playing music: " << filename << endl;

    SDL_Quit();
}

int main() {
    playMusic("OS.wav");
    return 0;
}
