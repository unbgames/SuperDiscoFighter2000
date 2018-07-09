#ifndef MUSIC_NOTE_BEHAVIOR
#define MUSIC_NOTE_BEHAVIOR

#include "Component.hpp"
#include "Sound.hpp"
#include "HUDTrack.hpp"
#include <string>

class MusicNoteBehavior: public Component {

    private:
        Sound* sound = nullptr;

    public:
        HUDTrack* track = nullptr;
        GameObject* vinil = nullptr;
        bool CheckInsideVinil(float offset);
        void Play();
        void AddSound(std::string name);
        bool isLast = false;

    // Overrides
    public:
        MusicNoteBehavior(GameObject& associated);
        void Start();
        void Update(float dt);
        void Render();
        bool Is(string type);

        void NotifyCollision(GameObject& other);

};

#endif