#include "BeatManager.hpp"

#include <iostream>

BeatManager& BeatManager::GetInstance() 
{
	static BeatManager instance;
	return instance;
}

BeatManager::BeatManager() : isBeat {false}
{
	beatTimer = Timer();
    
    beatOffset = 10.0f;
}

BeatManager::~BeatManager() 
{
}

void BeatManager::Update(float dt)
{
    beatTimer.Update(dt);

    //printf("%lf\n", beatTimer.Get());

    if(beatTimer.Get() >= beatOffset)
    {
        isBeat = true;
        beatTimer.Restart();
    }
    else if(beatTimer.Get() >= BEAT_DELTA_TIME)
    {
        isBeat = false;
    }
}

bool BeatManager::IsBeat()
{
    return isBeat;
}

float BeatManager::GetNextOffset()
{
    return beatOffset;
}

