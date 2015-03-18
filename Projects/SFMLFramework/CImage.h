#ifndef _CIMAGE_H_
    #define _CIMAGE_H_

#include <SFML/Graphics.hpp>

#include <unordered_map>

class CImage {
    public:
        CImage();

    public:
        static sf::Image* OnLoad(std::string filename);

        static sf::Image* OnLoad(std::string filename, sf::Color transparentColour);

        static sf::Image* getImage(std::string filename);

    private:

        static std::unordered_map<std::string, sf::Image*> images;
};

#endif
