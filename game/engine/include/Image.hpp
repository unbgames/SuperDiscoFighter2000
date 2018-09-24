#ifndef IMAGE_HPPPP
#define IMAGE_HPPPP

#include "Component.hpp"
// #include "Constants.hpp"

#include <string>

using std::string;

class Image: public Component{

    private:
        SDL_Texture* loadImage(string path);
        float width, height;

    public:
        Image(string path){ texture = loadImage(path); }
        SDL_Texture* texture;
        int x, y;
        void render();
        void update();
};


#endif