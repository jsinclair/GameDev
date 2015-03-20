#include "CPlayer.h"

CPlayer::CPlayer() {
}

bool CPlayer::OnLoad(std::string  File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

bool CPlayer::OnLoad(sf::Texture* texture, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(texture, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender(sf::RenderWindow* window) {
    CEntity::OnRender(window);
}

void CPlayer::OnCleanup() {
    CEntity::OnCleanup();
}

void CPlayer::OnAnimate() {
    if(SpeedX != 0) {
        Anim_Control.MaxFrames = 8;
    }else{
        Anim_Control.MaxFrames = 0;
    }

    CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity) {
    return Jump();
}
