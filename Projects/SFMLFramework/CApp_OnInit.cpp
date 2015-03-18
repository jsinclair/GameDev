#include "CApp.h"

bool CApp::OnInit() {
    if ((window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!")) == NULL) {
        return false;
    }

    if ((testTexture = CSurface::OnLoad("BabyTof.png")) == NULL) {
        return false;
    }

    if ((yoshiTexture = CSurface::OnLoad("yoshi.bmp")) == NULL) {
        return false;
    }

    yoshi.MaxFrames = 8;
    yoshi.Oscillate = false;

    return true;
}
