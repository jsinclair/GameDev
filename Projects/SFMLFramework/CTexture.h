#ifndef _CTEXTURE_H_
    #define _CTEXTURE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class CTexture {
    public:
        CTexture();

    public:
        static sf::Texture* OnLoad(std::string filename);

        static bool OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, int xPos, int yPos);

        static bool OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, int xPos, int yPos, int xSub, int ySub, int subWidth, int subHeight);

//        static bool OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, const sf::IntRect &area=sf::IntRect());
};

#endif
