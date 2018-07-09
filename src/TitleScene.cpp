#include "TitleScene.hpp"

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "StageScene.hpp"
#include "Game.hpp"
#include "Camera.hpp"
#include "Text.hpp"

TitleScene::TitleScene()
{
    GameObject* title = new GameObject();
    Sprite* titleSprite = new Sprite(*title, "games/SuperDiscoFighter2000/assets/img/menu.jpg");
    title->AddComponent(titleSprite);
    title->box.w = titleSprite->GetWidth();
    title->box.h = titleSprite->GetHeight();
    title->box.x = title->box.y = 0;

    objectArray.emplace_back(title);

    Camera::Unfollow();
    Camera::pos = Vec2(0, 0);

    GameObject* titleMessage = new GameObject();
    titleMessage->AddComponent(new Text(*titleMessage, "games/SuperDiscoFighter2000/assets/font/60sPop.ttf", 60, Text::TextStyle::BLENDED, "Press Space to dance!", {255, 255, 255, 255}, 3.0));
    titleMessage->box.y = Game::GetInstance().GetHeight()/1.2;
    titleMessage->box.x = Game::GetInstance().GetWidth()/6;
    objectArray.emplace_back(titleMessage);
}

void TitleScene::Update(float dt)
{
    if(InputManager::GetInstance().KeyPress(SDLK_ESCAPE) || InputManager::GetInstance().QuitRequested())
    {
        popRequested = true;
		quitRequested = true;
	}

    if(InputManager::GetInstance().KeyPress(SDLK_SPACE))
    {
		StageScene* stageScene = new StageScene();
        Game::GetInstance().Push(stageScene);
	}

    UpdateArray(dt);
}

TitleScene::~TitleScene()
{

}

void TitleScene::LoadAssets()
{

}

void TitleScene::Render()
{
    RenderArray();
}

void TitleScene::Start()
{
    LoadAssets();

    StartArray();
}

void TitleScene::Pause()
{
    
}

void TitleScene::Resume()
{
    
}