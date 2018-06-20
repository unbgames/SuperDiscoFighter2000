#include "HUDTrack.hpp"

#include "Game.hpp"
#include "Sprite.hpp"

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
    for(int i = 0; i < beats.size(); ++i)
    {
        beats[i]->box.x += 10;
        beats[i]->Update(dt);
        printf("x pos %lf\n", beats[i]->box.x);
    }
    // if(beats[beats.size()-1]->box.x - (direction)*Game::GetInstance().GetWidth()/2 > 0);
    // {
    //     beats.pop_back();
    // }
}

void HUDTrack::AddBeat()
{
    GameObject* note = new GameObject();
    Sprite* musicNote = new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/music_note.png");
    note->AddComponent(musicNote);
	note->box.y = associated.box.y;
	note->box.x = associated.box.x;
    beats.push_back((std::unique_ptr<GameObject>)note);
}

bool HUDTrack::Is(std::string type)
{
    return type == "HUDTrack";
}

