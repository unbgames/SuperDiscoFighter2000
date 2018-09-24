#include "InputManager.hpp"

#include "BeatManager.hpp"
#include "Resources.hpp"


InputManager& InputManager::GetInstance() 
{
	static InputManager instance;
	return instance;
}

InputManager::InputManager() : mouseState {false}, mouseUpdate {0}
{
	updateCounter = 0;
	quitRequested = false;
	mouseX = 0;
	mouseY = 0;
}

InputManager::~InputManager() 
{
	keyState.clear();
	keyUpdate.clear();
}

void InputManager::Update()
{
	SDL_Event event;
	SDL_GetMouseState(&mouseX, &mouseY);

	quitRequested = false;
	updateCounter++;

	while (SDL_PollEvent(&event))
    {
		if (event.type == SDL_QUIT) 
        {
			quitRequested = true;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) 
        {
			mouseState[event.button.button] = true;
			mouseUpdate[event.button.button] = updateCounter;
		}
		if (event.type == SDL_MOUSEBUTTONUP) 
        {
			mouseState[event.button.button] = false;
			mouseUpdate[event.button.button] = updateCounter;
		}
		if (event.type == SDL_KEYDOWN) 
        {
			if (event.key.repeat != 1) 
            {
				keyState[event.key.keysym.sym] = true;
				keyUpdate[event.key.keysym.sym] = updateCounter;
			}
		}
		if (event.type == SDL_KEYUP) 
        {
			keyState[event.key.keysym.sym] = false;
			keyUpdate[event.key.keysym.sym] = updateCounter;
		}
	}
}

bool InputManager::KeyPress(int key) 
{
	if(keyUpdate[key] == updateCounter && keyState[key] && BeatManager::GetInstance().IsBeat())
	{
		// this logic should not be here
	}
	return keyUpdate[key] == updateCounter && keyState[key];
}

bool InputManager::KeyRelease(int key) 
{
	return keyUpdate[key] == updateCounter && !keyState[key];
}

bool InputManager::IsKeyDown(int key) 
{
	return keyState[key];
}

bool InputManager::MousePress(int button)
{
	return mouseUpdate[button] == updateCounter && mouseState[button];
}

bool InputManager::MouseRelease(int button)
{
	return mouseUpdate[button] == updateCounter && !mouseState[button];
}

bool InputManager::IsMouseDown(int button)
{
	return mouseState[button];
}

int InputManager::GetMouseX()
{
	return mouseX;
}

int InputManager::GetMouseY()
{
	return mouseY;
}

bool InputManager::QuitRequested()
{
	return quitRequested;
}