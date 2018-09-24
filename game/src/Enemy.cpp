#include "Enemy.hpp"

#include "InputManager.hpp"
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Game.hpp"
#include "BeatManager.hpp"
#include "config.h"


#define MAX_TIME 2
#define MIN_TIME 15

Enemy* Enemy::enemy;

Enemy::Enemy(GameObject& associated, GameObject* player) : Component(associated), player(player)
{
    associated.AddComponent(new Collider(associated));
    
    Sprite* sprite = new Sprite(associated, ASSETS_PATH("/img/enemy_iddle.png"), 4, 1.5);
    associated.AddComponent(sprite);
    
    associated.box.w = sprite->GetWidth();
    associated.box.h = sprite->GetHeight();

    state = MOVING;
    stateTimer = Timer();
    moved = false;
    hp = 50;
    
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
    // printf("distance %lf\n", associated.box.Center().Distance(player->box.Center()));
    // printf("angle %lf\n", (180 / M_PI) * atan2(player->box.Center().y - associated.box.Center().y, player->box.Center().x - associated.box.Center().x));

    // associated.angleDeg = (180 / M_PI) * atan2((InputManager::GetInstance().GetMouseY() + Camera::pos.y - associated.box.Center().y), (InputManager::GetInstance().GetMouseX() + Camera::pos.x - associated.box.Center().x));

    int distanceAngle = (180 / M_PI) * atan2(player->box.Center().y - associated.box.Center().y, player->box.Center().x - associated.box.Center().x);
    int distance = associated.box.Center().Distance(player->box.Center());

    if(hp <= 0)
    {
        associated.RequestDelete();
    }

    

    if(state == MOVING)
    {
        if(BeatManager::GetInstance().IsBeat() and not moved)
        {
            // printf("x %lf\n", associated.box.x);
            // printf("y %lf\n", associated.box.y);
            moved = true; 
            int action = (distanceAngle > 0 and distanceAngle < 180)? 2: 1;
            // printf("ACTION %d\n", action);

            switch(action)
            {
                case 1:
                    if(Game::GetInstance().GetHeight()/3 < associated.box.y)
                    {
                        associated.box.y -= 10;
                    }
                break;

                case 2:
                    if(Game::GetInstance().GetHeight() - 320 > associated.box.y)
                    {
                        associated.box.y += 10;
                    }
                break;
            }
            
            associated.box.x -= 10;

            // state = RESTING;
            // stateTimer.Restart();
            // associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            // associated.AddComponent(new Sprite(associated, ASSETS_PATH("/img/enemy_rest.png")));
        }
        else if(not BeatManager::GetInstance().IsBeat())
        {
            moved = false;
        }
        if(distance < 100)
        {
            state = PUNCH;
            stateTimer.Restart();

            associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            associated.AddComponent(new Sprite(associated, ASSETS_PATH("/img/enemy_punch.png"), 4, 1));
        }
    }
    else if(state == PUNCH)
    {
        stateTimer.Update(dt);

        if (stateTimer.Get() > 4.f)
        {
            state = MOVING;
            associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            associated.AddComponent(new Sprite(associated, ASSETS_PATH("/img/enemy_iddle.png"), 4, 1.5));
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
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE))
    {
        hp -= 10;
        associated.box.x += 2;   
    }
}
