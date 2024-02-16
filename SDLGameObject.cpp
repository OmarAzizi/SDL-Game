#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params) {
    x = params->getX();
    y = params->getY();
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw() {
    TextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame, TheGame::Instance()->getRenderer());
}
