#include "Game.h"

Game* g_game = 0;

int main(int argc, char** argv) {
    g_game = new Game();
    
    g_game->init("SDL Game", 100, 100, 640, 480, true);
    
    while (g_game->isRunning()) {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();

    return 0;
}
