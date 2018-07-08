#include "HUDTrack.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"

HUDTrack::HUDTrack(GameObject& associated, TrackDirection direction) : Component(associated), direction(direction)
{
    
}

void HUDTrack::Render()
{
    for(int i = 0; i < beats.size(); ++i)
    {
        beats[i]->Render();
    }    
}

void HUDTrack::Update(float dt)
{
    if(InputManager::GetInstance().MousePress(1))
    {
        printf("x %d y %d\n", InputManager::GetInstance().GetMouseX(), InputManager::GetInstance().GetMouseY());
    }

    for(int i = 0; i < beats.size(); ++i)
    {
        beats[i]->box.x += 8.2*direction;
        beats[i]->Update(dt);
    }

    if(beats.size() > 0)
    {
        // printf("width %d\n", Game::GetInstance().GetWidth()/2);
        // printf("box x %d %lf\n", direction, beats[0]->box.x);
        if((Game::GetInstance().GetWidth()/2 - beats[0]->box.x) < 20 and direction == LEFT)
        {
            beats.erase(beats.begin());
        }
        else if((beats[0]->box.x - Game::GetInstance().GetWidth()/2) < 20 and direction == RIGHT)
        {
            beats.erase(beats.begin());
        }
    }
}

void HUDTrack::AddBeat()
{
    GameObject* note = new GameObject();
    Sprite* musicNote = new Sprite(*note, "games/SuperDiscoFighter2000/assets/img/music_note.png");
    note->AddComponent(musicNote);
	note->box.y = associated.box.y;
	note->box.x = (direction == LEFT ? 0: Game::GetInstance().GetWidth());
    beats.push_back((std::unique_ptr<GameObject>)note);
}

bool HUDTrack::Is(std::string type)
{
    return type == "HUDTrack" + std::to_string(direction);
}

