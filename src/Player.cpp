#include "../headers/Player.h"

Player::Player(const LoaderParams* params) : SDLGameObject(params) {}

void Player::draw() { SDLGameObject::draw(); }

void Player::update() { 
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
    acceleration.setX(1);
    SDLGameObject::update();
}

void Player::clean() {}
