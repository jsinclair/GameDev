#ifndef _CIMAGE_H_
    #define _CIMAGE_H_

#include <SFML/Graphics.hpp>

#include <map>

class CImage {
    public:
        CImage();

        static std::map<std::string,sf::Image*> images;

    public:
        static sf::Image* OnLoad(std::string filename);

        static sf::Image* OnLoad(std::string filename, sf::Color transparentColour);
};

#endif
