#include <iostream>

#include "CApp.h"

void CApp::OnEvent(sf::Event* event) {
    CEvent::OnEvent(event);
}

void CApp::OnExit() {
    running = false;
}

void CApp::OnKeyPressed(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W:
            CCamera::CameraControl.setVerticalMovement(UP);
            break;
        case sf::Keyboard::A:
            CCamera::CameraControl.setHorizontalMovement(LEFT);
            break;
        case sf::Keyboard::S:
            CCamera::CameraControl.setVerticalMovement(DOWN);
            break;
        case sf::Keyboard::D:
            CCamera::CameraControl.setHorizontalMovement(RIGHT);
            break;
        default:
            break;
    }
}

void CApp::OnKeyReleased(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Escape:
            running = false;
            break;
        case sf::Keyboard::D:
        case sf::Keyboard::A:
            CCamera::CameraControl.setHorizontalMovement(STATIONARY);
            break;
        case sf::Keyboard::W:
        case sf::Keyboard::S:
            CCamera::CameraControl.setVerticalMovement(STATIONARY);
            break;
        default:
            break;
    }
}
