#ifndef _CMAP_H_
    #define _CMAP_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

class CMap {
    public:
        sf::Texture* textureTileset;

    private:
        std::vector<CTile> TileList;

    public:
        CMap();

    public:
        bool OnLoad(std::string file);
        bool OnLoad(sf::Texture* texture);

        void OnRender(sf::RenderWindow* window, int mapX, int mapY);
};

#endif
