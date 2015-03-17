#include "CApp.h"

void CApp::OnEvent(sf::Event* event) {
    switch (event->type) {
        case sf::Event::Closed:
            running = false;
            break;
        default:
            break;
    }
}
