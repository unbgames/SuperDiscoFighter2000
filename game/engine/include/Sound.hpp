#ifndef SOUND_HPP
#define SOUND_HPP

#include <iostream>
#include <memory>

#include "EngineSDL.hpp"

#include "GameObject.hpp"
#include "Component.hpp"

using std::string;

class Sound: public Component
{
    private:
        std::shared_ptr<Mix_Chunk> chunk;
        int channel;

    public:
        Sound(GameObject& associated);
        Sound(GameObject& associated, string file);
        ~Sound();

        void Play(int times = 1);
        void Stop();
        void Open(string file);
        bool IsOpen();

        void Start();
        void Update(float dt);
        void Render();
        bool Is(string type);
};

#endif