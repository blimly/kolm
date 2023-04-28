#include <SDL2/SDL.h>

float render(SDL_Renderer* renderer) {
    float deltaTime = 0.0f;

    // Clear screen
    SDL_RenderClear(renderer);

    // Draw game graphics
    // ...

    // Update screen
    SDL_RenderPresent(renderer);

    return deltaTime;
}
