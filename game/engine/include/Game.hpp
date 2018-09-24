#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stack>

#include "EngineSDL.hpp"

#include "Scene.hpp"

using std::string;

class Game
{
    private:
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        Scene* storedScene;
        std::stack<std::unique_ptr<Scene>> sceneStack;

        int frameStart;
        float dt;
        void CalculateDeltaTime();
        Uint32 CalculateFrameTimeLeft();
        const Uint32 tickRate = 30;
        Uint32 nextTime;

        int width;
        int height;

    public:
        ~Game();

        void Init(string title, int width, int height);
        static Game& GetInstance();
        void Run();
        SDL_Renderer* GetRenderer();

        Scene& GetCurrentScene();
        void Push(Scene* scene);
        
        float GetDeltaTime();

        int GetHeight();
        int GetWidth();
};

#endif
