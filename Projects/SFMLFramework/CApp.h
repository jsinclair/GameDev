#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SFML/Graphics.hpp>

#include "CSurface.h"

class CApp {
    private:
        bool running;

        sf::RenderWindow *window;

        sf::Texture *testTexture;

    public:
        CApp();

        int OnExecute();

    public:

        bool OnInit();

        void OnEvent(sf::Event* event);

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

#endif
