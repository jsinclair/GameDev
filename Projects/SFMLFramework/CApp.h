#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SFML/Graphics.hpp>

#include "Define.h"

#include "CArea.h"
#include "CCamera.h"
#include "CEvent.h"
#include "CTexture.h"
#include "CImage.h"
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

        void OnLoop();

        void OnRender();

        void OnCleanup();

    public:
        // Event mothods
        void OnExit();

        virtual void OnKeyPressed(sf::Keyboard::Key key);

        virtual void OnKeyReleased(sf::Keyboard::Key key);
};

#endif
