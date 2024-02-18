#include "../headers/Enemy.h"

Enemy::Enemy(const LoaderParams* params) : SDLGameObject(params) {}

void Enemy::draw() { SDLGameObject::draw(); }

void Enemy::update() {
    currentFrame = int ( ((SDL_GetTicks() / 100) % 6) );
    position.setX(position.getX() + 1);
    position.setY(position.getY() + 1);
}

void Enemy::clean() {}
