#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "Component.hpp"
#include "Timer.hpp"

class Player : public Component
{
    private:
        enum PlayerState {MOVING, PUNCH};

        PlayerState state;

        Timer punchTimer;
        float punchOffset;

        int hp;
    
    public:
        static Player* player;

        Player(GameObject& associated);
        ~Player();

        void Start();
        void Update(float dt);
        void Render();
        bool Is(std::string type);

        void NotifyCollision (GameObject& other);
};

#endif
