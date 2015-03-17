#include "CSurface.h"

#include <iostream>

CSurface::CSurface() {
}

sf::Texture* CSurface::OnLoad(std::string filename) {
    sf::Texture* texture = new sf::Texture();

    if(!texture->loadFromFile(filename)) {
        return NULL;
    }

    return texture;
}

bool CSurface::OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, const sf::IntRect &area) {
    if(destWindow == NULL || srcTexture == NULL) {
        return false;
    }

    sf::Sprite sprite;
    sprite.setTexture(*srcTexture);
    //sprite.setTextureRect(area);

    destWindow->draw(sprite);

    return true;
}
