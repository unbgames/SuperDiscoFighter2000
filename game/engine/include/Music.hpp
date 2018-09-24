#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <iostream>
#include <memory>

#include "EngineSDL.hpp"

using std::string;

class Music
{
    private:
        std::shared_ptr<Mix_Music> music;

    public:
        Music();
        Music(string file);
        ~Music();

        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(string file); 
        bool IsOpen();
};

#endif