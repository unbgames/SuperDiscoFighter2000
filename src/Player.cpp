#include "Player.hpp"

#include "InputManager.hpp"
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Game.hpp"
#include "BeatManager.hpp"
#include "Camera.hpp"

#define STEP_LENGHT 50
#define STEP_LATERAL_LENGHT 30

Player* Player::player;

Player::Player(GameObject& associated) : Component(associated)
{
    associated.AddComponent(new Collider(associated));
    
    Sprite* sprite = new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/player_iddle.png", 4, 1);
    associated.AddComponent(sprite);
    
    associated.box.w = sprite->GetWidth();
    associated.box.h = sprite->GetHeight();

    state = MOVING;
    punchTimer = Timer();
    punchOffset = 3;
}

Player::~Player()
{
    player = nullptr;
}

void Player::Start()
{

}

void Player::Update(float dt)
{
    if(state == MOVING)
    {
        // printf("x %lf\n", associated.box.x);
        // printf("y %lf\n", associated.box.y);
        // if(BeatManager::GetInstance().IsBeat())
        // {
        //     printf("isBeat: %d\n", BeatManager::GetInstance().IsBeat());
        // }

        if(InputManager::GetInstance().KeyPress(SDLK_UP))
        {
            if(Game::GetInstance().GetHeight()/4 < associated.box.y)
            {
                associated.box.y -= STEP_LATERAL_LENGHT;
                associated.box.x -= STEP_LATERAL_LENGHT;
            }
        }
        if(InputManager::GetInstance().KeyPress(SDLK_DOWN))
        {
            if(Game::GetInstance().GetHeight() - 300 > associated.box.y)
            {
                associated.box.y += STEP_LATERAL_LENGHT;
                associated.box.x += STEP_LATERAL_LENGHT;
            }
        }
        if(InputManager::GetInstance().KeyPress(SDLK_LEFT))
        {
            if(associated.box.x < Game::GetInstance().GetWidth()/2 + 50)
            {
                // Camera::Unfollow();
            }
            if(associated.box.x > 0)
            {
                associated.box.x -= STEP_LENGHT;
            }
        }
        if(InputManager::GetInstance().KeyPress(SDLK_RIGHT))
        {
            if(associated.box.x > Game::GetInstance().GetWidth()/2)
            {
                // Camera::Follow(&associated);
            }
            else
            {
                // Camera::Unfollow();
            }
            associated.box.x += STEP_LENGHT;
        }
        if(InputManager::GetInstance().KeyPress(SDLK_SPACE))
        {
            state = PUNCH;
            punchTimer.Restart();

            associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            if(InputManager::GetInstance().IsKeyDown(SDLK_RIGHT))
            {      
                associated.AddComponent(new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/player_punch_up.png", 3, 1));
            }
            else
            {
                associated.AddComponent(new Sprite(associated, (rand()%2 == 1 ? "games/SuperDiscoFighter2000/assets/img/player_punch_left.png" : "games/SuperDiscoFighter2000/assets/img/player_punch_right.png"), 5, 0.6));
            }
        }
    }
    else if(state == PUNCH)
    {
        punchTimer.Update(dt);

        if (punchTimer.Get() > punchOffset)
        {
            state = MOVING;
            associated.RemoveComponent((Sprite *)associated.GetComponent("Sprite"));
            associated.AddComponent(new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/player_iddle.png", 4, 1));
        }
    }
}

void Player::Render()
{

}

bool Player::Is(std::string type)
{
    return type == "Player";
}


void Player::NotifyCollision (GameObject& other)
{

}