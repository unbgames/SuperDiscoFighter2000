#include "HUDTrack.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include "MusicNoteBehavior.hpp"


HUDTrack::HUDTrack(GameObject& associated, TrackDirection direction) : Component(associated), direction(direction)
{
    // Nothing
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
        beats[i]->box.x += direction * dt * (bpm*0.2);
        beats[i]->Update(dt);

        if(beats.size() > 0)
        {

            float diff = beats[0]->box.x - (Game::GetInstance().GetWidth()/2);

            if (direction == RIGHT){
                if( diff < 0 )
                {
                    beats.erase(beats.begin());
                    SetLast();
                }
            }else{
                if( diff > -24 )
                {
                    beats.erase(beats.begin());
                    SetLast();
                }
            }
            
            
        }
    }
}

void HUDTrack::AddBeat()
{
    GameObject* note = CreateBeat();
    beats.push_back((std::unique_ptr<GameObject>)note);

    if(beats.size() == 1) {
        printf("Defining Last note\n");
        GetScript(note)->isLast = true;
    }
}

GameObject* HUDTrack::CreateBeat()
{
    GameObject* note = new GameObject();
    Sprite* musicNote = new Sprite(*note, "games/SuperDiscoFighter2000/assets/img/music_note.png");
    musicNote->denyCamera = true;
    note->AddComponent(musicNote);

    MusicNoteBehavior* script = new MusicNoteBehavior(*note);
    script->vinil = vinil;
    script->track = this;
    script->AddSound("kick 1.wav");

    note->AddComponent( script );

    int distance = -12;

    if (direction == RIGHT){
        distance = Game::GetInstance().GetWidth() - 24;
    }

    note->box.y = associated.box.y + 30;
	note->box.x = distance;

    return note;
}

bool HUDTrack::RemoveBeatIfIsLast(GameObject* beat)
{
    if(beats.size() > 0) {
        // beats.erase(beats.begin());
        // SetLast();
        return true;
    }

    return false;
}

bool HUDTrack::Is(std::string type)
{
    return type == "HUDTrack" + std::to_string(direction);
}

MusicNoteBehavior* HUDTrack::GetScript(GameObject* beat){
    return (MusicNoteBehavior*) beat->GetComponent("MusicNoteBehavior");
}

void HUDTrack::SetLast(){

    if(beats.size() > 0) {
        MusicNoteBehavior* lastNote = (MusicNoteBehavior*) beats[0]->GetComponent("MusicNoteBehavior");
        lastNote->isLast = true;
    }

}
