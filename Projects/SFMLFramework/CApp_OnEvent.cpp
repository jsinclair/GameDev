#include "CApp.h"

void CApp::OnEvent(sf::Event* event) {
    CEvent::OnEvent(event);
}

void CApp::OnExit() {
    running = false;
}
