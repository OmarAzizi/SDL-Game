#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen == true) flags = SDL_WINDOW_FULLSCREEN;
    // init the window
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window != 0) {
        std::cout << "Window creation success\n";
        renderer = SDL_CreateRenderer(window, -1, 0);

        // renderer init success
        if (renderer != 0) { 
            std::cout << "Renderer creation success\n";
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        } else {
            std::cout << "renderer init failed\n";
            return false; // Renderer init fail
        }
    } else {
        std::cout << "window init failed\n";
        return false; // Window init fail
    }

    if (SDL_INIT_EVENTS != 0) 
        std::cout << "events init success\n";
    else {
        std::cout << "event init failed\n";
        isGameRunning = false;
        return false;
    }

    // To load texture with id "animate"
    if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", renderer)) 
        return false;

    std::cout << "init success\n";
    isGameRunning = true; // Everything initialized successfully, start the main loop
    
    return true;
}

/*
    render function clears the render and then 
    renders again with the clear color
*/
void Game::render() {
    SDL_RenderClear(renderer); // clear the renderer to draw the color
    
    TheTextureManager::Instance()->draw("animate", 0, 0, 137, 82, renderer);
    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 137, 82, 1, currentFrame, renderer);

    SDL_RenderPresent(renderer); // draw the screen
}

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isGameRunning = false;
                break;
            default: break;
        }
    }
}

void Game::update() {
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}
