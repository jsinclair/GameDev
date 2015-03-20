#ifndef _CCAMERA_H_
    #define _CCAMERA_H_

#include <SFML/Graphics.hpp>

#include "Define.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

enum {
    STATIONARY = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class CCamera {
    public:
        static CCamera CameraControl;

    private:
        double X;
        double Y;

        int* TargetX;
        int* TargetY;

    private:
        // movement stuff
        int FrameRate;

        long OldTime;

        sf::Clock clock;

        int horizontalMovement = STATIONARY;
        int verticalMovement = STATIONARY;

        int defaultSpeed = 5;

    public:
        int TargetMode;

    public:
        CCamera();

    public:
        void OnMove(int MoveX, int MoveY);

        void OnLoop();

    public:
        int GetX();
        int GetY();

        void setHorizontalMovement(int direction);
        void setVerticalMovement(int direction);

    public:
        void SetPos(double X, double Y);

        void SetTarget(int* X, int* Y);
};

#endif
