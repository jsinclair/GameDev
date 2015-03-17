#include "CApp.h"

bool CApp::OnInit() {
    if ((window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!")) == NULL) {
        return false;
    }

    return true;
}
