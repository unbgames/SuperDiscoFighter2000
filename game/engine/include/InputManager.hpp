#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "EngineSDL.hpp"

#include <unordered_map>
#include <iostream>
#include "GameObject.hpp"

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT

class InputManager
{
    private:
        bool mouseState[6];
        int mouseUpdate[6];

        std::unordered_map<int, bool> keyState;
        std::unordered_map<int, int> keyUpdate;

        bool quitRequested;

        int updateCounter;

        int mouseX;
        int mouseY;

        InputManager();
        ~InputManager();

        GameObject* observer = nullptr;

    public:
        static InputManager& GetInstance();

        void Update();
        
        bool KeyPress(int key);
        bool KeyRelease(int key);
        bool IsKeyDown(int key);

        bool MousePress(int button);
        bool MouseRelease(int button);
        bool IsMouseDown(int button);

        int GetMouseX();
        int GetMouseY();

        bool QuitRequested();
};

#endif