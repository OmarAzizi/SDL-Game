#include "../headers/SDLGameObject.h"
#include "../headers/TextureManager.h"
#include "../headers/Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) 
    : GameObject(params), position(params->getX(), params->getY()) , velocity(0, 0), acceleration(0, 0)
{    
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw() {
    TextureManager::Instance()->drawFrame(textureID, (int)position.getX(), 
            (int)position.getY(), width, height, currentRow, currentFrame, 
            TheGame::Instance()->getRenderer());
}

void SDLGameObject::update() {
    velocity += acceleration;
    position += velocity;
}
