#ifndef BEATMANAGER_HPP
#define BEATMANAGER_HPP

#include "Timer.hpp"

#define BEAT_DELTA_TIME 1.f

class BeatManager
{
    private:
        float beatOffset;
        Timer beatTimer;
        bool isBeat;

        BeatManager();
        ~BeatManager();
    
    public:
        static BeatManager& GetInstance();

        void Update(float dt);
        bool IsBeat();
        void SetBeatOffset(float beatOffset);
};

#endif