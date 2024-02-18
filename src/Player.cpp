#include "../headers/Player.h"
#include "../headers/InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw() { SDLGameObject::draw(); }

void Player::update() {
	currentFrame = int(((SDL_GetTicks() / 100) % 6));
	
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		velocity.setX(2);
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		velocity.setX(-2);
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		velocity.setY(-2);
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		velocity.setY(2);
	
	SDLGameObject::update();
}

void Player::clean() {}
