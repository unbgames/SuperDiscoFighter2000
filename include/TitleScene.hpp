#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "Scene.hpp"

class TitleScene : public Scene
{
    public:
        TitleScene();
        ~TitleScene();

        void LoadAssets();
        void Update(float dt);
        void Render();

        void Start();
        void Pause();
        void Resume();  
};

#endif