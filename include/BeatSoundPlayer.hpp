#ifndef BEAT_SOUND_PLAYER
#define BEAT_SOUND_PLAYER

#include "Component.hpp"
#include "Sound.hpp"

class BeatSoundPlayer: public Component {

    private:
        Sound* kickBeat = nullptr;
        Sound* palmBeat1 = nullptr;
        Sound* palmBeat2 = nullptr;
        Sound* palmBeat3 = nullptr;

    public:
        void PlayPalm();
        void PlayKick();

    public:
        BeatSoundPlayer(GameObject& associated);
        void Start();
        void Update(float dt);
        void Render();
        bool Is(string type);

};

#endif