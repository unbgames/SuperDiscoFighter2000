#ifndef HUDTRACK_HPP
#define HUDTRACK_HPP

#include "Component.hpp"

#include <memory>
#include <vector>

class MusicNoteBehavior;

class HUDTrack : public Component
{
    public:
        enum TrackDirection {RIGHT = -1, LEFT = 1};
        float bpm = 80;

        GameObject* vinil;

        HUDTrack(GameObject& associated, TrackDirection direction);

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        
        void AddBeat();
        bool RemoveBeatIfIsLast(GameObject* beat);
        void SetLast();
    
    private:
        GameObject* CreateBeat();
        MusicNoteBehavior* GetScript(GameObject* beat);
        TrackDirection direction;
        std::vector<std::unique_ptr<GameObject>> beats;
};

#endif