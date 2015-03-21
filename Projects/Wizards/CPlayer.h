#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include "CEntity.h"

class CPlayer : public CEntity {
    public:
        CPlayer();

        bool OnLoad(std::string File, int Width, int Height, int MaxFrames);

        bool OnLoad(sf::Texture* texture, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(sf::RenderWindow* window);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);
};

#endif
