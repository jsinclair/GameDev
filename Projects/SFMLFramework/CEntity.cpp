#include "CEntity.h"

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity() {
    Surf_Entity = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

    AnimState = 0;
}

CEntity::~CEntity() {
}

bool CEntity::OnLoad(std::string File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
        return false;
    }

//    CSurface::Transparent(Surf_Entity, 255, 0, 255);

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

bool CEntity::OnLoad(sf::Texture* texture, int Width, int Height, int MaxFrames) {
    if(texture == NULL) {
        return false;
    }
    Surf_Entity = texture;

//    CSurface::Transparent(Surf_Entity, 255, 0, 255);

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

void CEntity::OnLoop() {
    Anim_Control.OnAnimate();
}

void CEntity::OnRender(sf::RenderWindow* window) {
    if(Surf_Entity == NULL || window == NULL) return;

    CSurface::OnDraw(window, Surf_Entity, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
}

void CEntity::OnCleanup() {
    Surf_Entity = NULL;
}
