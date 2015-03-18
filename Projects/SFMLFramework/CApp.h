#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SFML/Graphics.hpp>

#include "CAnimation.h"
#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
    private:
        bool running;

        sf::RenderWindow *window;

        sf::Texture *testTexture;

        sf::Texture *yoshiTexture;

        CAnimation yoshi;

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(sf::Event* event);

        void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

#endif
