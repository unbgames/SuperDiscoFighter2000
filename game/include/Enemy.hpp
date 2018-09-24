#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

#include "Component.hpp"
#include "Timer.hpp"

class Enemy : public Component
{
    private:
        enum EnemyState {MOVING, RESTING, PUNCH};

        EnemyState state;

        Timer stateTimer;
        float stateOffset;

        bool moved;
        int hp;

        GameObject* player;
    
    public:
        static Enemy* enemy;

        Enemy(GameObject& associated, GameObject* player);
        ~Enemy();

        void Start();
        void Update(float dt);
        void Render();
        bool Is(std::string type);

        void NotifyCollision (GameObject& other);
};

#endif
