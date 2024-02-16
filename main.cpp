#include "Game.h"

Game* g_game = 0;

int main() {
    g_game = new Game();
    g_game->init("SDL Game", 100, 100, 640, 480, false);

    while (g_game->isRunning()) {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();

    return 0;
}
