#include "CCamera.h"

#include <iostream>

CCamera CCamera::CameraControl;

CCamera::CCamera() {
    X = Y = 0;

    TargetX = TargetY = NULL;

    TargetMode = TARGET_MODE_NORMAL;

    FrameRate = FRAMERATE;
    OldTime = clock.getElapsedTime().asMilliseconds();
}

void CCamera::OnLoop() {
    double movementMod = (double)(clock.getElapsedTime().asMilliseconds() - OldTime) / (double)FrameRate;

    OldTime = clock.getElapsedTime().asMilliseconds();

    switch (horizontalMovement) {
        case LEFT:
            this->OnMove(defaultSpeed * movementMod, 0);
            break;
        case RIGHT:
            this->OnMove(-defaultSpeed * movementMod, 0);
            break;
        default:
            break;
    }

    switch (verticalMovement) {
        case UP:
            this->OnMove(0, defaultSpeed * movementMod);
            break;
        case DOWN:
            this->OnMove(0, -defaultSpeed * movementMod);
            break;
        default:
            break;
    }
}

void CCamera::OnMove(int MoveX, int MoveY) {
    X += MoveX;
    Y += MoveY;
}

int CCamera::GetX() {
    if(TargetX != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
            return *TargetX - (WWIDTH / 2);
        }

        return *TargetX;
    }

    return X;
}

int CCamera::GetY() {
    if(TargetY != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
            return *TargetY - (WHEIGHT / 2);
        }

        return *TargetY;
    }

    return Y;
}

void CCamera::SetPos(double X, double Y) {
    this->X = X;
    this->Y = Y;
}

void CCamera::SetTarget(int* X, int* Y) {
    TargetX = X;
    TargetY = Y;
}

void CCamera::setHorizontalMovement(int direction) {
    horizontalMovement = direction;
}

void CCamera::setVerticalMovement(int direction) {
    verticalMovement = direction;
}
