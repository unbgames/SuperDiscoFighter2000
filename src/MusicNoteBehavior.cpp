#include "MusicNoteBehavior.hpp"

#include <string>
#include "EngineSDL.hpp"
#include "InputManager.hpp"

MusicNoteBehavior::MusicNoteBehavior(GameObject& associated) : Component(associated)
{
    // std::string asset_path = "games/SuperDiscoFighter2000/assets/audio/percussao/";

    // //Initialize sounds
    // kickBeat =  new Sound( associated, asset_path + "kick 1.wav");
    // palmBeat1 = new Sound( associated, asset_path + "clap 1.wav");
    // palmBeat2 = new Sound( associated, asset_path + "clap 2.wav");
    // palmBeat3 = new Sound( associated, asset_path + "clap 3.wav");
}

void MusicNoteBehavior::Start()
{
    
}

void MusicNoteBehavior::Update(float dt)
{
    if ( CheckInsideVinil( 10 ) ){

        if ( InputManager::GetInstance().KeyPress(SDLK_DOWN) ){
            Play();
            if ( track != nullptr ){
                if ( track->RemoveBeatIfIsLast(&associated) ){
                    printf("RIGHT YEAH! \n");
                }else{
                    printf("not removed \n");
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