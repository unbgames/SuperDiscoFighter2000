#include "HUD.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "HUDTrack.hpp"
#include "BeatManager.hpp"

HUD::HUD(GameObject& associated) : Component(associated)
{
	Sprite* vinylSprite = new Sprite(associated, "games/SuperDiscoFighter2000/assets/img/vinyl_disc.png");
    associated.AddComponent(vinylSprite);
	associated.box.y = 500;
	associated.box.x = Game::GetInstance().GetWidth()/2 - vinylSprite->GetWidth()/2;

	leftTrack = new GameObject();
	leftTrack->AddComponent(new HUDTrack(associated, HUDTrack::TrackDirection::LEFT));
	leftTrack->box.y = associated.box.y;
	leftTrack->box.x = associated.box.x;

	noteRendered = false;
}

void HUD::Update(float dt)
{
	((HUDTrack *)leftTrack->GetComponent("HUDTrack"))->Update(dt);
	if(BeatManager::GetInstance().IsBeat() and not noteRendered)
	{
		noteRendered = true;
		((HUDTrack *)leftTrack->GetComponent("HUDTrack"))->AddBeat();
	}
	else
	{
		noteRendered = false;
	}
}

void HUD::Render()
{
	((HUDTrack *)leftTrack->GetComponent("HUDTrack"))->Render();
}

bool HUD::Is(std::string type)
{
    return type == "HUD";
}

