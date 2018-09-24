#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <memory>

#include "EngineSDL.hpp"

#include "Component.hpp"
#include "GameObject.hpp"
#include "Timer.hpp"

class Sprite : public Component
{
    private:
        std::shared_ptr<SDL_Texture> texture;
        int width;
        int height;
        SDL_Rect clipRect;
        Vec2 scale;

        int frameCount;
        int currentFrame;
        float timeElapsed;
        float frameTime;

        Timer selfDestructCount;
		float secondsToSelfDestruct;

    public:
        Sprite(GameObject& associated);
        Sprite(GameObject& associated, std::string file, int frameCount = 1, float frameTime = 1.f, float secondsToSelfDestruct = 0);
        ~Sprite();

        bool denyCamera = false;

        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        int GetWidth();
        int GetHeight();
        bool IsOpen();

        void SetScaleX(float scaleX, float scaleY);
        Vec2 GetScale();

        void Start();
        void Update(float dt);
        void Render();
        void Render(float x, float y);
        bool Is(string type);

        void SetFrame(int frame);
        void SetFrameCount(int frameCount);
        void SetFrameTime(float frameTime);
};

#endif