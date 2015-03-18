#include "CApp.h"

bool CApp::OnInit() {
    if ((window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!")) == NULL) {
        return false;
    }

    testTexture = new sf::Texture();
    yoshiTexture = new sf::Texture();

    if (CImage::OnLoad("BabyTof.png") == NULL ||
        !testTexture->loadFromImage(*CImage::getImage("BabyTof.png"))) {
        return false;
    }

    if (CImage::OnLoad("yoshi.png", sf::Color(255, 0, 255)) == NULL ||
        !yoshiTexture->loadFromImage(*CImage::getImage("yoshi.png"))) {
        return false;
    }

    if(entity1.OnLoad(yoshiTexture, 64, 64, 8) == false) {
        return false;
    }

    if(entity2.OnLoad(yoshiTexture, 64, 64, 8) == false) {
        return false;
    }

    entity2.X = 100;

    CEntity::EntityList.push_back(&entity1);
    CEntity::EntityList.push_back(&entity2);

    return true;
}
