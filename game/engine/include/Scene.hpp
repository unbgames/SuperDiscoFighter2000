#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "GameObject.hpp"

class Scene
{
    protected:
        bool popRequested;
        bool quitRequested;
        bool started;
        std::vector<std::shared_ptr<GameObject> > objectArray;
    
        virtual void StartArray();
        virtual void UpdateArray(float dt);
        virtual void RenderArray();

    public:
        Scene();
        virtual ~Scene();
        
        virtual void LoadAssets() = 0;
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;

        virtual void Start() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual std::weak_ptr<GameObject> AddObject(GameObject* object);
        virtual std::weak_ptr<GameObject> GetObjectPtr(GameObject* object);
    
        bool PopRequested();
        bool QuitRequested();
};

#endif