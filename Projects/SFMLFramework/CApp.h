#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SFML/Graphics.hpp>

class CApp {
    private:
        bool running;

        sf::RenderWindow *window;

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
