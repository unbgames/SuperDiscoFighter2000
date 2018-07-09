#ifndef HUD_HPP
#define HUD_HPP

#include "Component.hpp"

class HUD : public Component
{
    private:
        GameObject* leftTrack;
        GameObject* rightTrack;
        GameObject* vinil;

        bool noteRendered;

    public:
        HUD(GameObject& associated);

        void Update(float dt);
        void Render();
        bool Is(std::string type);

    // Prefab
    private:
        GameObject* CreateVinil();

};

#endif