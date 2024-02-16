#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
public:
    Enemy(const LoaderParams* params);

    void draw();
    void update();
    void clean();
};

#endif
