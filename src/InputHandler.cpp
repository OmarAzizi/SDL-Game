#include "../headers/InputHandler.h"
#include "../headers/Game.h"

InputHandler* InputHandler::s_pInstance = nullptr;

void InputHandler::update() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				TheGame::Instance()->quit();
				break;
			case SDL_KEYDOWN:
				onKeyDown();
				break;
			case SDL_KEYUP:
				onKeyUp();
				break;
			default:
				break;
		}
	}
}
	
void InputHandler::onKeyDown() { m_keystates = SDL_GetKeyboardState(nullptr); }

void InputHandler::onKeyUp() { m_keystates = SDL_GetKeyboardState(nullptr); }

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keystates != 0) {
		if (m_keystates[key] == 1) return true;
		else return false;
	}
	return false;
}
