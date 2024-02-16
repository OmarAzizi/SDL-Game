#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "LoaderParams.h"

class GameObject {
protected:
    GameObject(const LoaderParams* params) {}
    virtual ~GameObject() {}
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};

#endif
