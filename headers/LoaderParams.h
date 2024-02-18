#ifndef __LOADER_PARAMS_H__
#define __LOADER_PARAMS_H__

#include <string>

class LoaderParams {
    int x, y;
    int width, height;
    std::string textureID;
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID) 
        : x(x), y(y), width(width), height(height), textureID(textureID) {}
    
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::string getTextureID() const { return textureID; }
};

#endif
