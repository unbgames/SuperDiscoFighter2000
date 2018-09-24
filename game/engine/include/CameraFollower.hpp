#ifndef CAMERAFOLLOWER_HPP
#define CAMERAFOLLOWER_HPP

#include <iostream>

#include "Component.hpp"
#include "GameObject.hpp"

class CameraFollower : public Component
{
    public:
        CameraFollower (GameObject& go);

        void Start();
        void Update (float dt);
        void Render ();
        bool Is (std::string type);
};

#endif
