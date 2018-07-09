#include "HUD.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "HUDTrack.hpp"
#include "BeatManager.hpp"
#include "Camera.hpp"

HUD::HUD(GameObject& associated) : Component(associated)
{
	Sprite* vinylSprite = new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/vinyl_disc.png");
    associated.AddComponent(vinylSprite);

	leftTrack = new GameObject();
	leftTrack->AddComponent(new HUDTrack(associated, HUDTrack::TrackDirection::LEFT));

	rightTrack = new GameObject();
	rightTrack->AddComponent(new HUDTrack(associated, HUDTrack::TrackDirection::RIGHT));

	leftTrack->box.y = rightTrack->box.y = associated.box.y;
	leftTrack->box.x = rightTrack->box.y = associated.box.x;

	noteRendered = false;
}

void HUD::Update(float dt)
{
	associated.box.y = Camera::pos.y + 505;
	associated.box.x = Camera::pos.x + Game::GetInstance().GetWidth()/2 - 48;
	
	((HUDTrack *)leftTrack->GetComponent("HUDTrack1"))->Update(dt);
	((HUDTrack *)rightTrack->GetComponent("HUDTrack-1"))->Update(dt);
	if(BeatManager::GetInstance().IsBeat())
	{
		if(not noteRendered)
		{
			noteRendered = true;
			((HUDTrack *)leftTrack->GetComponent("HUDTrack1"))->AddBeat();
			((HUDTrack *)rightTrack->GetComponent("HUDTrack-1"))->AddBeat();
		}
	}
	else
	{
		noteRendered = false;
	}
}

void HUD::Render()
{	
	((HUDTrack *)leftTrack->GetComponent("HUDTrack1"))->Render();
	((HUDTrack *)rightTrack->GetComponent("HUDTrack-1"))->Render();
}

bool HUD::Is(std::string type)
{
    return type == "HUD";
}

