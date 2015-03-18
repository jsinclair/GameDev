#include "CTexture.h"

#include <iostream>

CTexture::CTexture() {
}

sf::Texture* CTexture::OnLoad(std::string filename) {
    sf::Texture* texture = new sf::Texture();

    if(!texture->loadFromFile(filename)) {
        return NULL;
    }

    return texture;
}

bool CTexture::OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, int xPos, int yPos) {
    if(destWindow == NULL || srcTexture == NULL) {
        return false;
    }

    sf::Vector2u textureSize = srcTexture->getSize();

    return CTexture::OnDraw(destWindow, srcTexture, xPos, yPos, 0, 0, textureSize.x, textureSize.y);
}

bool CTexture::OnDraw(sf::RenderWindow* destWindow, sf::Texture* srcTexture, int xPos, int yPos, int xSub, int ySub, int subWidth, int subHeight) {
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
