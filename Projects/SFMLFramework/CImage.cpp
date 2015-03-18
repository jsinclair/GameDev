#include "CImage.h"

#include <iostream>

std::unordered_map<std::string, sf::Image*> CImage::images;

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

sf::Image* CImage::getImage(std::string filename) {
    // Check if the entry exists in the map.
    std::unordered_map<std::string, sf::Image*>::const_iterator got = images.find(filename);

    // If it doesn't, attempt to add it.
    if (got == images.end()) {
        return CImage::OnLoad("BabyTof.png");
    }
    else {
        return got->second;
    }
}
