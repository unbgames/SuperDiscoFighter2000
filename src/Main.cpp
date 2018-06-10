#include "Game.hpp"
#include "TitleScene.hpp"

int main()
{
    Game::GetInstance().Init("Super Disco Fighter 2000", 1024, 600);
    Game::GetInstance().Push(new TitleScene());
    Game::GetInstance().Run();
    Game::GetInstance().~Game();

    return 0;
}
