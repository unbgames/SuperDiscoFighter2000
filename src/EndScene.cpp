#include "EndScene.hpp"

#include "GameData.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "StageScene.hpp"
#include "Game.hpp"
#include "Camera.hpp"
#include "Text.hpp"

EndScene::EndScene()
{
    GameObject* bg = new GameObject();
    if(GameData::playerVictory) 
    {
        bg->AddComponent(new Sprite(*bg, "games/SuperDiscoFighter2000/assets/img/menu.jpg"));
        backgroundMusic = Music("games/SuperDiscoFighter2000/assets/audio/endSceneWin.ogg");
    } 
    else 
    {
        bg->AddComponent(new Sprite(*bg, "games/SuperDiscoFighter2000/assets/img/menu.jpg"));
        backgroundMusic = Music("games/SuperDiscoFighter2000/assets/audio/endSceneLose.ogg");
    }
    backgroundMusic.Play(1);
    objectArray.emplace_back(bg);

    Camera::Unfollow();
    Camera::pos = Vec2(0, 0);

    std::string titleStr = (GameData::playerVictory? "You dance!": "You lose!");
    std::cout << titleStr << std::endl;
    
    GameObject* titleMessage = new GameObject();
    // titleMessage->AddComponent(new Text(*titleMessage, "games/SuperDiscoFighter2000/assets/font/60sPop.ttf", 50, Text::TextStyle::BLENDED, titleStr, {255, 255, 255, 255}, 5.0));
    titleMessage->box.y = Game::GetInstance().GetHeight()/1.2;
    titleMessage->box.x = Game::GetInstance().GetWidth()/6;
    objectArray.emplace_back(titleMessage);
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