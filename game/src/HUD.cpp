#include "HUD.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "HUDTrack.hpp"
#include "BeatManager.hpp"
#include "Camera.hpp"
#include "Collider.hpp"
#include "config.h"

HUD::HUD(GameObject& associated) : Component(associated)
{

	associated.box.y = 505;
	associated.box.x = 0;

	vinil = CreateVinil();

	// Criando left track, track poderia ser um prefab
	leftTrack = new GameObject();
	HUDTrack* left = new HUDTrack(associated, HUDTrack::TrackDirection::LEFT);
	left->vinil = vinil;

	leftTrack->AddComponent(left);

	
	// Criando right track, track poderia ser um prefab
	rightTrack = new GameObject();
	HUDTrack* right = new HUDTrack(associated, HUDTrack::TrackDirection::RIGHT);
	right->vinil = vinil;

	rightTrack->AddComponent(right);


	// definindo posicoes iniciais
	leftTrack->box.y = rightTrack->box.y = associated.box.y;
	leftTrack->box.x = rightTrack->box.y = associated.box.x;

	noteRendered = false;
}

void HUD::Update(float dt)
{
	vinil->Update(dt);

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
	vinil->Render();
	((HUDTrack *)leftTrack->GetComponent("HUDTrack1"))->Render();
	((HUDTrack *)rightTrack->GetComponent("HUDTrack-1"))->Render();
}

bool HUD::Is(std::string type)
{
    return type == "HUD";
}



// Prefabs
GameObject* HUD::CreateVinil()
{
	GameObject* obj = new GameObject();
	Sprite* vinylSprite = new Sprite(*obj, ASSETS_PATH("/img/vinyl_disc.png"));
	vinylSprite->denyCamera = true;
    obj->AddComponent(vinylSprite);
	obj->box.x = Game::GetInstance().GetWidth()/2 - 48;
	obj->box.y = 505;
	obj->name = "vinil";

	return obj;
}
// end - Prefabs
