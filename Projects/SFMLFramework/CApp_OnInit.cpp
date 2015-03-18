#include "CApp.h"

bool CApp::OnInit() {
    if ((window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!")) == NULL) {
        return false;
    }

    testTexture = new sf::Texture();
    yoshiTexture = new sf::Texture();

    if(!testTexture->loadFromImage(*CImage::OnLoad("BabyTof.png"))) {
        return false;
    }

    if(!yoshiTexture->loadFromImage(*CImage::OnLoad("yoshi.png"))) {
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
