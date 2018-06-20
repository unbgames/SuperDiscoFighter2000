#ifndef HUDTRACK_HPP
#define HUDTRACK_HPP

#include "Component.hpp"

#include <memory>
#include <vector>

class HUDTrack : public Component
{
    public:
        enum TrackDirection {RIGHT = -1, LEFT = 1};

        HUDTrack(GameObject& associated, TrackDirection direction);

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        
        void AddBeat();
    
    private:
        TrackDirection direction;
        std::vector<std::unique_ptr<GameObject>> beats;
};

#endif