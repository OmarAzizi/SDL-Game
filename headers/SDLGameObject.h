#ifndef __SDL_GAME_OBJECT_H__
#define __SDL_GAME_OBJECT_H__

#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* params);

    virtual void draw();
    virtual void update();
    virtual void clean() {}
protected:
    Vector2D position, acceleration, velocity;
    int width, height;
    int currentRow, currentFrame;
    std::string textureID;
};

#endif
