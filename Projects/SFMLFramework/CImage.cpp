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

    CImage::images[filename] = image;

    return image;
}

sf::Image* CImage::OnLoad(std::string filename, sf::Color transparentColour) {
    sf::Image* image = CImage::OnLoad(filename);

    if (image != NULL) {
        image->createMaskFromColor(transparentColour);
    }

    return image;
}
