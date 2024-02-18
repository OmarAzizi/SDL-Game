#include "../headers/Game.h"
#include <SDL2/SDL_stdinc.h>

Game* g_game = 0;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main() {
    Uint32 frameStart, frameTime;

    std::cout << "game init attempt ...\n";
    if (TheGame::Instance()->init("SDL Game", 100, 100, 640, 480, false)) {
        std::cout << "game init success!\n";
        while (TheGame::Instance()->isRunning()) {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME)
                SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    } else {
        std::cout << "game init faliure - " << SDL_GetError() << "\n";
        return -1;
    }
    std::cout << "game closing ...\n";
    TheGame::Instance()->clean();

    return 0;
}
