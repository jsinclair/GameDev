#include "CApp.h"
#include "define.h"

bool CApp::OnInit() {
    if ((window = new sf::RenderWindow(sf::VideoMode(WWIDTH, WHEIGHT), "SFML works!")) == NULL) {
        return false;
    }

    if (CImage::OnLoad("BabyTof.png") == NULL) {
        return false;
    }

    if (CImage::OnLoad("yoshi.png") == NULL) {
        return false;
    }

    if (CImage::OnLoad("skeleton.png") == NULL) {
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

    skeleTexture = CTexture::OnLoad(CImage::getImage("skeleton.png"));

    if (skeleTexture == NULL) {
        return false;
    }

    if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
        return false;
    }

    if(Player.OnLoad(yoshiTexture, 64, 64, 8) == false) {
        return false;
    }

    npc.owner = &Player;

    if(npc.OnLoad(skeleTexture, 25, 48, 3) == false) {
        return false;
    }

    npc.X = 100;

    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&npc);

    for (int i = 0; i < 5; i++) {
        CSkeleton *skele = new CSkeleton();
        skele->owner = &Player;

        if(skele->OnLoad(skeleTexture, 25, 48, 3) == false) {
            return false;
        }

        skele->X = i * 200;
        skele->Y = i * 75;

        CEntity::EntityList.push_back(skele);
    }

    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

    return true;
}
