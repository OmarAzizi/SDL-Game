#include "../headers/Game.h"

Game* g_game = 0;

int main() {
    std::cout << "game init attempt ...\n";
    if (TheGame::Instance()->init("SDL Game", 100, 100, 640, 480, false)) {
        std::cout << "game init success!\n";
        while (TheGame::Instance()->isRunning()) {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            SDL_Delay(10);
        }
    } else {
        std::cout << "game init faliure - " << SDL_GetError() << "\n";
        return -1;
    }
    std::cout << "game closing ...\n";
    TheGame::Instance()->clean();

    return 0;
}
