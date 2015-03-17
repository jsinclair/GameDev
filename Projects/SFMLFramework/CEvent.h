
#ifndef _CEVENT_H_
    #define _CEVENT_H_

#include <SFML/Graphics.hpp>

class CEvent {
    public:
        CEvent();

        virtual ~CEvent();

        virtual void OnEvent(sf::Event* event);

        virtual void OnExit();
};

#endif
