#include "EngineSDL.hpp"

#include "StageScene.hpp"
#include "Sprite.hpp"
#include "Sound.hpp"
#include "TileMap.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include "CameraFollower.hpp"
#include "Collider.hpp"
#include "Collision.hpp"
#include "TitleScene.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "HUD.hpp"
#include "Enemy.hpp"

StageScene::StageScene()
{
    quitRequested = false;
	started = false;

    backgroundMusic = Music("games/SuperDiscoFighter2000/assets/audio/all_body1.wav");
    backgroundMusic.Play(-1);
        
    GameObject* bg = new GameObject();
    bg->AddComponent(new Sprite(*bg, "games/SuperDiscoFighter2000/assets/img/background.png"));
	// bg->AddComponent(new CameraFollower(*bg));
	bg->box.y = -100;
	objectArray.emplace_back(bg);

	GameObject* HUDGO = new GameObject();
	HUDGO->AddComponent(new HUD(*HUDGO));
	// HUDGO->AddComponent(new CameraFollower(*HUDGO));
	objectArray.emplace_back(HUDGO);	

	/*
	GameObject* map = new GameObject();
	TileSet* tile = new TileSet(*map, 64, 64, "sample_assets/img/tileset.png");
	TileMap* tileMap = new TileMap(*map, "sample_assets/map/tileMap.txt", tile);
	map->box.y = map->box.x = 0;
	map->AddComponent(tileMap);
	objectArray.emplace_back(map);
	*/

	GameObject* playerGO = new GameObject();
	Player* player = new Player(*playerGO);
	playerGO->box.x = 140;
	playerGO->box.y = 150;
	playerGO->AddComponent(player);
	objectArray.emplace_back(playerGO);

	GameObject* enemyGO = new GameObject();
	Enemy* enemy = new Enemy(*enemyGO);
	enemyGO->box.x = 540;
	enemyGO->box.y = 160;
	enemyGO->AddComponent(enemy);
	objectArray.emplace_back(enemyGO);

	/*
	enemyGO = new GameObject();
	enemy = new Enemy(*enemyGO);
	enemyGO->box.x = 540;
	enemyGO->box.y = 100;
	enemyGO->AddComponent(enemy);
	objectArray.emplace_back(enemyGO);

	enemyGO = new GameObject();
	enemy = new Enemy(*enemyGO);
	enemyGO->box.x = 540;
	enemyGO->box.y = 300;
	enemyGO->AddComponent(enemy);
	objectArray.emplace_back(enemyGO);
	*/

	// Camera::pos.x = Camera::pos.y = 0;
	Camera::Follow(playerGO);
}

StageScene::~StageScene()
{
    objectArray.clear();
}

void StageScene::LoadAssets()
{
	
}

void StageScene::Start()
{
	LoadAssets();

	StartArray();
}

void StageScene::Update(float dt)
{
	Camera::Update(dt);

	if(InputManager::GetInstance().KeyPress(SDLK_ESCAPE) || InputManager::GetInstance().QuitRequested())
	{
		popRequested = true;
		TitleScene* titleScene = new TitleScene();
        Game::GetInstance().Push(titleScene);
	}

	UpdateArray(dt);

	for(int i = 0; i < (int) objectArray.size(); ++i) 
	{
		Collider* a = (Collider*)objectArray[i]->GetComponent("Collider");
		if (a != nullptr) 
		{
			for(int j = i+1; j < (int) objectArray.size(); ++j) 
			{
				Collider* b = (Collider*)objectArray[j]->GetComponent("Collider");
				if (b != nullptr) 
				{
					if (Collision::IsColliding(a->box, b->box, objectArray[i]->angleDeg * (M_PI / 180), objectArray[j]->angleDeg * M_PI / 180)) 
					{
						objectArray[i]->NotifyCollision(*objectArray[j].get());
						objectArray[j]->NotifyCollision(*objectArray[i].get());
					}
				}
			}
		}
	}


	for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		if(objectArray[i]->IsDead())
		{
			objectArray.erase(objectArray.begin() + i);
		}
	}
}

void StageScene::Render()
{
	for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		// if(objectArray[i]->GetComponent("HUD") != nullptr)
		// {
		// 	objectArray[i]->box.x = Camera::pos.x;
		// 	objectArray[i]->box.y = Camera::pos.y;
		// }
		objectArray[i]->Render();
	}
}

void StageScene::Pause()
{

}

void StageScene::Resume()
{

}