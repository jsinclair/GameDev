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
        case sf::Keyboard::Left:
            Player.MoveLeft = true;
            break;
        case sf::Keyboard::Right:
            Player.MoveRight = true;
            break;
        case sf::Keyboard::Space:
            Player.Jump();
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
        case sf::Keyboard::Left:
            Player.MoveLeft = false;
            break;
        case sf::Keyboard::Right:
            Player.MoveRight = false;
            break;
        default:
            break;
    }
}
