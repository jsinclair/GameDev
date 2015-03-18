#include <vector>

#include <SFML/Graphics.hpp>

#include "CAnimation.h"
#include "CTexture.h"

class CEntity {
    public:
        static std::vector<CEntity*> EntityList;

    protected:
        CAnimation      Anim_Control;

        sf::Texture*    texture_Entity;

    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        int             AnimState;

    public:
        CEntity();

        virtual ~CEntity();

    public:
        virtual bool OnLoad(std::string File, int Width, int Height, int MaxFrames);

        virtual bool OnLoad(sf::Texture* texture, int Width, int Height, int MaxFrames);

        virtual void OnLoop();

        virtual void OnRender(sf::RenderWindow* window);

        virtual void OnCleanup();
};
