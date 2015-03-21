#ifndef _CFPS_H_
    #define _CFPS_H_

#include <SFML/Graphics.hpp>

#include "define.h"

class CFPS {
    public:
        static CFPS FPSControl;

    private:
        int     OldTime;
        int     LastTime;

        float     SpeedFactor;

        int    NumFrames;
        int     Frames;

        sf::Clock clock;

    public:
        CFPS();

        void    OnLoop();

    public:
        int     GetFPS();

        float   GetSpeedFactor();
};

#endif
