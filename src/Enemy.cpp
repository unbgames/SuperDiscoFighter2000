#include "Enemy.hpp"

#include "InputManager.hpp"
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Game.hpp"
#include "BeatManager.hpp"


#define MAX_TIME 2
#define MIN_TIME 15

Enemy* Enemy::enemy;

Enemy::Enemy(GameObject& associated) : Component(associated)
{
    associated.AddComponent(new Collider(associated));
    
    Sprite* sprite = new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/enemy_iddle.png");
    associated.AddComponent(sprite);
    
    associated.box.w = sprite->GetWidth();
    associated.box.h = sprite->GetHeight();

    state = MOVING;
    stateTimer = Timer();
    moved = false;
    
    srand(time(NULL));
    stateOffset = rand() % MAX_TIME + MIN_TIME;
}

Enemy::~Enemy()
{
    enemy = nullptr;
}

void Enemy::Start()
{

}

void Enemy::Update(float dt)
{
    if(state == MOVING)
    {
        if(BeatManager::GetInstance().IsBeat() and not moved)
        {
            // printf("x %lf\n", associated.box.x);
            // printf("y %lf\n", associated.box.y);
            moved = true; 
            int action = rand() % 3 + 1;
            // printf("ACTION %d\n", action);

            switch(action)
            {
                case 1:
                    if(Game::GetInstance().GetHeight()/6 < associated.box.y)
                    {
                        associated.box.y += 45;
                        //associated.box.x -= 60;
                    }
                break;

                case 2:
                    if(Game::GetInstance().GetHeight() - 350 > associated.box.y)
                    {
                        associated.box.y -= 45;
                        //associated.box.x += 60;
                    }
                break;

                case 3:
                    associated.box.x -= 90;
                break;
            }
        }
        else if(not BeatManager::GetInstance().IsBeat())
        {
            moved = false;
        }
        if(InputManager::GetInstance().KeyPress(SDLK_SPACE))
        {
            state = PUNCH;
            stateTimer.Restart();

            associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            associated.AddComponent(new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/enemy_punch.png", 4, 1));
        }
    }
    else if(state == PUNCH)
    {
        stateTimer.Update(dt);

        if (stateTimer.Get() > 3.f)
        {
            state = MOVING;
            associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            associated.AddComponent(new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/enemy_iddle.png"));
        }
    }
    else if(state == RESTING)
    {
        stateTimer.Update(dt);

        if (stateTimer.Get() > stateOffset)
        {
            state = MOVING;
            stateOffset = rand() % MAX_TIME +  MIN_TIME;
        }
    }
}

void Enemy::Render()
{

}

bool Enemy::Is(std::string type)
{
    return type == "Enemy";
}


void Enemy::NotifyCollision(GameObject& other)
{

}