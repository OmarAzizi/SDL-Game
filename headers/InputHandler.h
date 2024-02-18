#ifndef __InputHandler__
#define __InputHandler__

#include <SDL2/SDL_keyboard.h>
#include <vector>
#include <utility>

#include <SDL2/SDL.h>
#include "./Vector2D.h"

class InputHandler {
    InputHandler() {}
	static InputHandler* s_pInstance;
	
	const Uint8* m_keystates = SDL_GetKeyboardState(nullptr);
	
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
public:
	static InputHandler* Instance() {
		if(s_pInstance == nullptr)
			s_pInstance = new InputHandler();
		return s_pInstance;
	}
	
	void update();
	bool isKeyDown(SDL_Scancode key);
};

typedef InputHandler TheInputHandler;

#endif // __InputHandler__
