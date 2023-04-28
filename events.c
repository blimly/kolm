#include <SDL2/SDL.h>

float handleEvents() {
    float deltaTime = 0.0f;

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            // Handle quit event...
            // ...
        }
        // Handle other events...
        // ...
    }

    return deltaTime;
}
