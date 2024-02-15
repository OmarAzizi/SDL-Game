#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>

class Game {
    bool isGameRunning = false;

    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    Game() {}
    ~Game() {}
    
    // simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen);

    void render();
    void update() {}
    void handleEvents();
    void clean();
    
    bool isRunning() { return isGameRunning; }
};

#endif /* defined (__GAME_H__) */
