#include "EndScene.hpp"

#include "GameData.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "StageScene.hpp"
#include "Game.hpp"

EndScene::EndScene()
{
    GameObject* bg = new GameObject();
    if(GameData::playerVictory) 
    {
        bg->AddComponent(new Sprite(*bg, "sample_assets/img/win.jpg"));
        backgroundMusic = Music("sample_assets/audio/endSceneWin.ogg");
    } 
    else 
    {
        bg->AddComponent(new Sprite(*bg, "sample_assets/img/lose.jpg"));
        backgroundMusic = Music("sample_assets/audio/endSceneLose.ogg");
    }
    backgroundMusic.Play(1);

    objectArray.emplace_back(bg);
}

void EndScene::Start()
{
    LoadAssets();

    StartArray();
}

void EndScene::Update(float dt)
{ 
    if(InputManager::GetInstance().KeyPress(SDLK_ESCAPE) || InputManager::GetInstance().QuitRequested())
    {
		quitRequested = true;
	}

    if(InputManager::GetInstance().KeyPress(SDLK_SPACE))
    {
        popRequested = true;
		StageScene *stageScene = new StageScene();
        Game::GetInstance().Push(stageScene);
	}

    UpdateArray(dt); 
}

void EndScene::Render()
{ 
    RenderArray(); 
}

void EndScene::LoadAssets()
{
    
}

void EndScene::Pause()
{

}

void EndScene::Resume()
{

}

EndScene::~EndScene()
{

}