#include "Scene.hpp"

Scene::Scene()
{
    quitRequested = false;
    popRequested = false;
    started = false;
}

Scene::~Scene()
{
    objectArray.clear();
}

std::weak_ptr<GameObject> Scene::AddObject(GameObject* go)
{
	std::shared_ptr<GameObject> goPtr(go);

	objectArray.push_back(goPtr);
	
	if(started)
	{
		go->Start();
	}

	return std::weak_ptr<GameObject> (goPtr);
}

std::weak_ptr<GameObject> Scene::GetObjectPtr(GameObject* go)
{
	for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		if(objectArray[i].get() == go)
		{
			return std::weak_ptr<GameObject> (std::shared_ptr<GameObject> (objectArray[i]));
		}
	}
	return std::weak_ptr<GameObject> ();
}

bool Scene::PopRequested()
{
    return popRequested;
}

bool Scene::QuitRequested()
{
    return quitRequested;
}

void Scene::StartArray()
{
    for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		objectArray[i].get()->Start();
	}

    started = true;
}

void Scene::UpdateArray(float dt)
{
    for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		objectArray[i].get()->Update(dt);
	}
}

void Scene::RenderArray()
{
    for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		objectArray[i].get()->Render();
	}
}
