#include "MusicNoteBehavior.hpp"

#include <string>
#include "EngineSDL.hpp"
#include "InputManager.hpp"
#include "Player.hpp"


MusicNoteBehavior::MusicNoteBehavior(GameObject& associated) : Component(associated)
{
}

void MusicNoteBehavior::Start()
{
    
}

void MusicNoteBehavior::Update(float dt)
{
    if ( CheckInsideVinil( 10 ) && !isBeaten ){
        if ( CheckPunchInput() || CheckMovimentInput() ){
            if ( track != nullptr && isLast ){
                if ( track->RemoveBeatIfIsLast(&associated) ){
                    Play();
                    isBeaten = true;
                    MovePlayer();
                }else{
                    // printf("not removed \n");
                }
            }
        }
    }
}

void MusicNoteBehavior::Render() 
{
    // Nothing
}

bool MusicNoteBehavior::Is(string type)
{
    return type == "MusicNoteBehavior";
}

void MusicNoteBehavior::Play()
{
    try {
        sound->Play(0);
    } catch (...) {
        printf("[ERROR] MusicNoteBehavior - Could not play sound...\n");
    }
}

bool MusicNoteBehavior::CheckInsideVinil( float offset )
{
    if (vinil != nullptr){

        float diff = associated.box.x - vinil->box.x + 12;
        float delta = 0;

        if(diff < 0){
            delta = abs(diff) - 12;
        }else{
            delta = abs(diff) - 96;
        }

        if (delta < offset){
            return true;
        }
    }

    return false;
}

void MusicNoteBehavior::AddSound(std::string name)
{
    std::string asset_path = "games/SuperDiscoFighter2000/assets/audio/percussao/";

    if(sound == nullptr){
        sound = new Sound( associated, asset_path + name);    
    }
}

void MusicNoteBehavior::NotifyCollision(GameObject& other)
{
    // Nothing
}

bool MusicNoteBehavior::CheckPunchInput(){
    return InputManager::GetInstance().KeyPress(SDLK_SPACE);
}

bool MusicNoteBehavior::CheckMovimentInput(){
    return InputManager::GetInstance().KeyPress(SDLK_DOWN) ||
            InputManager::GetInstance().KeyPress(SDLK_UP) ||
            InputManager::GetInstance().KeyPress(SDLK_RIGHT) ||
            InputManager::GetInstance().KeyPress(SDLK_LEFT);
}



void MusicNoteBehavior::MovePlayer()
{
    if(track->direction == HUDTrack::TrackDirection::RIGHT)
        return;

    Player* player = Player::player;

    if(player == nullptr){
        printf("player not found\n");
        return;
    }

    try {
        if(InputManager::GetInstance().KeyPress(SDLK_UP))
        {
            player->MoveUp();
        }
        else if(InputManager::GetInstance().KeyPress(SDLK_DOWN))
        {
            player->MoveDown();
        }
        else if(InputManager::GetInstance().KeyPress(SDLK_LEFT))
        {
            player->MoveLeft();
        }
        else if(InputManager::GetInstance().KeyPress(SDLK_RIGHT))
        {
            player->MoveRight();
        }
        else if(InputManager::GetInstance().KeyPress(SDLK_SPACE))
        {
            player->Punch();
        }else{

        }
    }
    catch (...) {
        printf("Quebrou\n");
    }
}