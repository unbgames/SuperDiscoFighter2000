#ifndef STAGESCENE_HPP
#define STAGESCENE_HPP

#include "Scene.hpp"
#include "Music.hpp"
#include "TileSet.hpp"

class StageScene : public Scene
{
    private:
        TileSet* tileSet;
        Music backgroundMusic;

    public:
        StageScene();
        ~StageScene();
        
        void LoadAssets();
        void Update(float dt);
        void Render();
        
        void Start();
        void Pause();
        void Resume();
};

#endif