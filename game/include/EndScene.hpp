#ifndef ENDSCENE_HPP
#define ENDSCENE_HPP

#include "Scene.hpp"
#include "Music.hpp"

class EndScene : public Scene
{
    private:
        Music backgroundMusic;
    
    public:
        EndScene();
        ~EndScene();

        void LoadAssets();
        void Update(float dt);
        void Render();

        void Start();
        void Pause();
        void Resume();
};

#endif