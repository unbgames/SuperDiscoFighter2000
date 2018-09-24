#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <unordered_map>
#include <memory>

#include "EngineSDL.hpp"

class Resources
{
    public:
        static std::shared_ptr<SDL_Texture> GetImage(std::string file);
        static void ClearImages();

        static std::shared_ptr<Mix_Music> GetMusic(std::string file);
        static void ClearMusics();

        static std::shared_ptr<Mix_Chunk> GetSound(std::string file);
        static void ClearSounds();

        static std::shared_ptr<TTF_Font> GetFont(std::string file, int ptsize);
        static void ClearFonts();

        static void ClearAll();

    private:
        static std::unordered_map<std::string, std::shared_ptr<SDL_Texture> > imageTable;
        static std::unordered_map<std::string, std::shared_ptr<Mix_Music> > musicTable;
        static std::unordered_map<std::string, std::shared_ptr<Mix_Chunk> > soundTable;
        static std::unordered_map<std::string, std::shared_ptr<TTF_Font> > fontTable;
};

#endif