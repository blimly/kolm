#include <SDL2/SDL.h>
#include <stdbool.h>

#include "update.h"
#include "events.h"
#include "render.h"

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int windowWidth = 1280;
    int windowHeight = 720;

    int fps = 60;
    int frameDelay = 1000 / fps;

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL2 could not be initialized! SDL2 Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("kolm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL2 Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Set window title to display FPS
    char windowTitle[256];
    sprintf(windowTitle, "My Game - %d FPS", fps);
    SDL_SetWindowTitle(window, windowTitle);

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) { printf("Renderer could not be created! SDL2 Error: %s\n", SDL_GetError()); SDL_DestroyWindow(window); SDL_Quit(); return 1; }

    // Set render color to black
    SDL_SetRenderDrawColor(renderer, 25, 23, 36, 255);

    // Clear screen
    SDL_RenderClear(renderer);

    // Update screen
    SDL_RenderPresent(renderer);

    // Wait for user to close window
    bool quit = false;
    SDL_Event e;

    Uint32 frameStart, frameTime;
    float deltaTime = 0.0f;

    while (!quit) {
        frameStart = SDL_GetTicks();

        deltaTime += update();
        deltaTime += handleEvents();
        deltaTime += render(renderer);

        // Limit frame rate
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
    }

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
