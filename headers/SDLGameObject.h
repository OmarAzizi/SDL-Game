#ifndef __SDL_GAME_OBJECT_H__
#define __SDL_GAME_OBJECT_H__

#include "GameObject.h"
#include <SDL2/SDL.h>

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* params);

    virtual void draw();
    virtual void update() {}
    virtual void clean() {}
protected:
    int x, y;
    int width, height;
    int currentRow, currentFrame;
    std::string textureID;
};

#endif
