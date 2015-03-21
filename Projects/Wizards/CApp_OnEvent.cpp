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
        case sf::Keyboard::Up:
            Player.MoveUp = true;
            break;
        case sf::Keyboard::Down:
            Player.MoveDown = true;
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
        case sf::Keyboard::Up:
            Player.MoveUp = false;
            break;
        case sf::Keyboard::Down:
            Player.MoveDown = false;
            break;
        default:
            break;
    }
}
