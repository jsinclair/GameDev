#include "CImage.h"

#include <iostream>

std::map<std::string,sf::Image*> CImage::images;

CImage::CImage() {
}

sf::Image* CImage::OnLoad(std::string filename) {
    sf::Image* image = new sf::Image();

    if(!image->loadFromFile(filename)) {
        return NULL;
    }

    image->createMaskFromColor(sf::Color(255, 0, 255));

    CImage::images[filename] = image;

    return image;
}
