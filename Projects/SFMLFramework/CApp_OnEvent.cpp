#include "CApp.h"

void CApp::OnEvent(sf::Event* event) {
    CEvent::OnEvent(event);
}

void CApp::OnExit() {
    running = false;
}

void CApp::OnKeyDown(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Escape:
            running = false;
            break;
        case sf::Keyboard::W:
            CCamera::CameraControl.OnMove( 0,  5);
            break;
        case sf::Keyboard::A:
            CCamera::CameraControl.OnMove( 5,  0); break;
            break;
        case sf::Keyboard::S:
            CCamera::CameraControl.OnMove( 0, -5);
            break;
        case sf::Keyboard::D:
            CCamera::CameraControl.OnMove(-5,  0);
            break;
        default:
            break;
    }
}
