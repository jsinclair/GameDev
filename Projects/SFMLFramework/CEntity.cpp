#include "CEntity.h"

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity() {
    texture_Entity = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

    AnimState = 0;
}

CEntity::~CEntity() {
}

bool CEntity::OnLoad(std::string File, int Width, int Height, int MaxFrames) {
    if((texture_Entity = CTexture::OnLoad(File)) == NULL) {
        return false;
    }

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

bool CEntity::OnLoad(sf::Texture* texture, int Width, int Height, int MaxFrames) {
    if(texture == NULL) {
        return false;
    }
    texture_Entity = texture;

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

void CEntity::OnLoop() {
    Anim_Control.OnAnimate();
}

void CEntity::OnRender(sf::RenderWindow* window) {
    if(texture_Entity == NULL || window == NULL) return;

    CTexture::OnDraw(window, texture_Entity, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
}

void CEntity::OnCleanup() {
    texture_Entity = NULL;
}
