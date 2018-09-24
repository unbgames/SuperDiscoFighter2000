#include "TileMap.hpp"

#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

#include "Camera.hpp"

#define PARALLAX_FACTOR 0.7

// Help class to delimited by comma
class WordDelimitedByComma : public std::string
{};

std::istream& operator>>(std::istream& is, WordDelimitedByComma& output)
{
   getline(is, output, ',');
   return is;
}

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) : Component(associated)
{
    Load(file);
    this->tileSet = tileSet;
}

void TileMap::Load(std::string file)
{
    std::ifstream in(file);
    std::string line;
    std::istringstream aux;
    std::vector<std::string> test;

    // Read Header
    getline(in, line);
    aux.str(line);
    copy(std::istream_iterator<WordDelimitedByComma>(aux), std::istream_iterator<WordDelimitedByComma>(), back_inserter(test));
    mapWidth = stoi(test[0]);
    mapHeight = stoi(test[1]);
    mapDepth = stoi(test[2]);    
    test.clear();

    // Read content
    copy(std::istream_iterator<WordDelimitedByComma>(in), std::istream_iterator<WordDelimitedByComma>(), back_inserter(test));
    std::transform(test.begin(), test.end(), std::back_inserter(tileMatrix), 
                    [](const std::string& str) { if(isdigit(str[str.length()-1])) return stoi(str)-1; else return -1; });
}

void TileMap::SetTileSet(TileSet* tileSet)
{
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z)
{
    return tileMatrix[y*mapWidth + x + z*(mapHeight*mapWidth)];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
    for(int i = 0; i < mapHeight; ++i)
    {
        for(int j = 0; j < mapWidth; ++j)
        {    
            tileSet->RenderTile(At(i, j, layer), (tileSet->GetTileWidth() * i) - cameraX, (tileSet->GetTileHeight() * j) - cameraY);
        }
    }
}

void TileMap::Render()
{
    for(int i = 0; i < mapDepth; ++i)
    {
        RenderLayer(i, Camera::pos.x, Camera::pos.y);    
    }
}

int TileMap::GetWidth()
{
    return mapWidth;
}

int TileMap::GetHeight()
{
    return mapHeight;
}

int TileMap::GetDepth()
{
    return mapDepth;
}

void TileMap::Update(float dt)
{

}
        
bool TileMap::Is(std::string type)
{
    return type == "TileMap";
}

void TileMap::Start() 
{

}

