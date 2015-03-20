#ifndef _CAREA_H_
    #define _CAREA_H_

#include <SFML/Graphics.hpp>

#include "CMap.h"

class CArea {
    public:
        static CArea            AreaControl;

    public:
        std::vector<CMap>       MapList;

    private:
        int                     AreaSize;

        sf::Texture*        tileset;

    public:
        CArea();

        bool    OnLoad(std::string);

        void    OnRender(sf::RenderWindow* window, int CameraX, int CameraY);

        void    OnCleanup();
};

#endif
