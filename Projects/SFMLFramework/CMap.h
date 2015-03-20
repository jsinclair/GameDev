#ifndef _CMAP_H_
    #define _CMAP_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "CTile.h"
#include "CTexture.h"

class CMap {
    public:
        sf::Texture* textureTileset;

    private:
        std::vector<CTile> TileList;

    public:
        CMap();

    public:
        bool OnLoad(std::string file);

        void OnRender(sf::RenderWindow* window, int mapX, int mapY);
};

#endif
