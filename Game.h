#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Game {
    Game() {}

    bool isGameRunning = false;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    int currentFrame; // Will allow us to animate our sprite sheet
    std::vector<GameObject*> gameObjects;

    static Game* instance;
public:
    ~Game() {}
    
    // simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen);

    void render();
    void update();
    void handleEvents();
    void clean();
    void draw();
    
    bool isRunning() { return isGameRunning; }

    static Game* Instance() {
        if(instance == 0) {
            instance = new Game();
            return instance;
        } 
        return instance;
    }
    
    SDL_Renderer* getRenderer() const { return renderer; }
};

typedef Game TheGame;

#endif /* defined (__GAME_H__) */
