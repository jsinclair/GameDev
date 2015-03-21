#include "CSkeleton.h"
#include "CApp.h"

#include <iostream>
#include <cmath>

CSkeleton::CSkeleton() {
    owner = NULL;
}

void CSkeleton::OnLoop() {
    CSkeleton::OnThink();

    CEntity::OnLoop();
}

void CSkeleton::OnThink() {
    if (owner->X < CEntity::X) {
        CEntity::MoveLeft = true;
    }
    else {
        CEntity::MoveLeft = false;
    }

    if (owner->X > CEntity::X) {
        CEntity::MoveRight = true;
    }
    else {
        CEntity::MoveRight = false;
    }

    if (owner->Y < CEntity::Y) {
        CEntity::MoveUp = true;
    }
    else {
        CEntity::MoveUp = false;
    }

    if (owner->Y > CEntity::Y) {
        CEntity::MoveDown = true;
    }
    else {
        CEntity::MoveDown = false;
    }
}

void CSkeleton::OnAnimate() {
    if(std::abs(SpeedX)  > std::abs(SpeedY)) {
        if (SpeedX < 0) {
            CurrentFrameCol = 0;
        }
        else if (SpeedX > 0) {
            CurrentFrameCol = 1;
        }
    } else if (std::abs(SpeedX) < std::abs(SpeedY)) {
        if (SpeedY < 0) {
            CurrentFrameCol = 2;
        }
        else if (SpeedY > 0) {
            CurrentFrameCol = 3;
        }
    }

    Anim_Control.OnAnimate();
}
