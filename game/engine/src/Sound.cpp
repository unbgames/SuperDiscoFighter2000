#include "Sound.hpp"
#include "Resources.hpp"

Sound::Sound(GameObject& associated) : Component(associated)
{
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, std::string file) : Sound(associated)
{
    Open(file);
}

void Sound::Play(int times)
{
    channel = Mix_PlayChannel(0, chunk.get(), times);
}

void Sound::Stop()
{
    if(chunk != nullptr)
        Mix_HaltChannel(channel);
}

void Sound::Open(std::string file)
{
    chunk = Resources::GetSound(file);
}

bool Sound::IsOpen()
{
    return chunk != nullptr; 
}

Sound::~Sound()
{
}

bool Sound::Is(std::string type)
{
    return type == "Sound";
}

void Sound::Render() {}

void Sound::Update(float dt) {}

void Sound::Start() {}