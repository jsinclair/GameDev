
#ifndef _CEVENT_H_
    #define _CEVENT_H_

#include <SFML/Graphics.hpp>

class CEvent {
    public:
        CEvent();

        virtual ~CEvent();

        virtual void OnEvent(sf::Event* event);

        virtual void OnExit();

        virtual void OnKeyPressed(sf::Keyboard::Key key);

        virtual void OnKeyReleased(sf::Keyboard::Key key);
};

#endif
