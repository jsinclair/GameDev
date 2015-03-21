#include "CEvent.h"

CEvent::CEvent() {
}

CEvent::~CEvent() {
    //Do nothing
}

void CEvent::OnEvent(sf::Event* event) {
    switch (event->type) {
        case sf::Event::Closed:
            OnExit();
            break;
        case sf::Event::KeyPressed:
            OnKeyPressed(event->key.code);
            break;
        case sf::Event::KeyReleased:
            OnKeyReleased(event->key.code);
            break;
        default:
            break;
    }
}

void CEvent::OnExit() {
    // Virtual, not actually going to be called
}

void CEvent::OnKeyPressed(sf::Keyboard::Key key) {
    // Virtual, not actually going to be called
}

void CEvent::OnKeyReleased(sf::Keyboard::Key key) {
    // Virtual, not actually going to be called
}
