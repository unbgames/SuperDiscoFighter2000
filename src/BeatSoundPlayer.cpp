#include "BeatSoundPlayer.hpp"

#include <string>

BeatSoundPlayer::BeatSoundPlayer(GameObject& associated) : Component(associated)
{
    std::string asset_path = "games/SuperDiscoFighter2000/assets/audio/percussao/";

    //Initialize sounds
    kickBeat =  new Sound( associated, asset_path + "kick 1.wav");
    palmBeat1 = new Sound( associated, asset_path + "clap 1.wav");
    palmBeat2 = new Sound( associated, asset_path + "clap 2.wav");
    palmBeat3 = new Sound( associated, asset_path + "clap 3.wav");
}

void BeatSoundPlayer::Start()
{
    
}

void BeatSoundPlayer::Update(float dt) 
{
    // Nothing
}

void BeatSoundPlayer::Render() 
{
    // Nothing
}

bool BeatSoundPlayer::Is(string type)
{
    return type == "BeatSoundPlayer";
}

void BeatSoundPlayer::PlayPalm()
{
    try {
        palmBeat1->Play(0);
        palmBeat2->Play(0);
        palmBeat3->Play(0);
    } catch (...) {
        printf("[ERROR] Could not play palm beat...\n");
    }
}

void BeatSoundPlayer::PlayKick()
{
    try {
        kickBeat->Play(0);
    } catch (...) {
        printf("[ERROR] Could not play kick beat...\n");
    }
}