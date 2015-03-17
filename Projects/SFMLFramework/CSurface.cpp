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

bool CSurface::OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, int xPos, int yPos) {
    if(destWindow == NULL || srcTexture == NULL) {
        return false;
    }

    sf::Vector2u textureSize = srcTexture->getSize();

    return CSurface::OnDraw(destWindow, srcTexture, xPos, yPos, 0, 0, textureSize.x, textureSize.y);
}

bool CSurface::OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, int xPos, int yPos, int xSub, int ySub, int subWidth, int subHeight) {
    if(destWindow == NULL || srcTexture == NULL) {
        return false;
    }

    sf::Sprite sprite;
    sprite.setTexture(*srcTexture);
    sprite.setPosition(xPos, yPos);
    sprite.setTextureRect(sf::IntRect(xSub, ySub, subWidth, subHeight));

    destWindow->draw(sprite);

    return true;
}
