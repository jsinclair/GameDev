#include "CApp.h"
#include "define.h"

bool CApp::OnInit() {
    if ((window = new sf::RenderWindow(sf::VideoMode(WWIDTH, WHEIGHT), "SFML works!")) == NULL) {
        return false;
    }

    if (CImage::OnLoad("BabyTof.png") == NULL) {
        return false;
    }

    if (CImage::OnLoad("yoshi.png", sf::Color(255, 0, 255)) == NULL) {
        return false;
    }

    testTexture = CTexture::OnLoad(CImage::getImage("BabyTof.png"));

    if (testTexture == NULL) {
        return false;
    }

    yoshiTexture = CTexture::OnLoad(CImage::getImage("yoshi.png"));

    if (yoshiTexture == NULL) {
        return false;
    }

    if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
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
