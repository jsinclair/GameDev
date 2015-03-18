#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SFML/Graphics.hpp>

#include "CAnimation.h"
#include "CEvent.h"
#include "CSurface.h"
#include "CEntity.h"

class CApp : public CEvent {
    private:
        bool running;

        sf::RenderWindow *window;

        sf::Texture *testTexture;

        sf::Texture *yoshiTexture;

        CEntity entity1;
        CEntity entity2;

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
