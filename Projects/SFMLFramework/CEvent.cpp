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
            OnKeyDown(event->key.code);
        default:
            break;
    }
}

void CEvent::OnExit() {
    // Virtual, not actually going to be called
}

void CEvent::OnKeyDown(sf::Keyboard::Key key) {
    // Virtual, not actually going to be called
}
