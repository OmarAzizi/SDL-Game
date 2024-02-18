#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <SDL2/SDL.h>
#include <string>
#include <map>

/*
    The texture manager will have functions that allow us to load 
    and create an SDL_Texture structure from an image file, draw 
    the texture (either static or animated), and also hold a list 
    of SDL_Texture* so tat we can user them whenever we need to.
*/
class TextureManager {
    // map of pointers to the SDL_Texture objects using string id
    std::map<std::string, SDL_Texture*> textureMap;

    static TextureManager* instance;
    TextureManager() {}; // Empty constructor
public:
    bool load(std::string filename, std::string id, SDL_Renderer* renderer);
    
    // draw
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, 
              SDL_RendererFlip flip = SDL_FLIP_NONE);

    // drawframe
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, 
                   int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    // Singelton class
    static TextureManager* Instance() {
        if(instance == 0) {
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }
};

typedef TextureManager TheTextureManager;

#endif
