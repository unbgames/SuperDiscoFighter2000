#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <iostream>
#include <string>

#include "Component.hpp"
#include "Rect.hpp"

using std::vector;
using std::string;

class GameObject 
{
    private:
        vector<Component*> components;
        bool isDead;
        bool started;
    
    public:
        GameObject();
        ~GameObject();

        void Start();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(string type);

        std::string name;

        void NotifyCollision(GameObject& other);

        Rect box;
        double angleDeg;
};

#endif