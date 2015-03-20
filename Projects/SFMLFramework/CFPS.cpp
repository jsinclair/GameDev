#include "CFPS.h"

#include <iostream>

CFPS CFPS::FPSControl;

CFPS::CFPS() {
    OldTime     = 0;
    LastTime    = 0;

    SpeedFactor    = 0;

    Frames      = 0;
    NumFrames   = 0;
}

void CFPS::OnLoop() {
    if(OldTime + 1000 < clock.getElapsedTime().asMilliseconds()) {
        OldTime = clock.getElapsedTime().asMilliseconds();

        NumFrames = Frames;

        Frames = 0;
    }

    SpeedFactor = ((float)(clock.getElapsedTime().asMilliseconds() - LastTime) / 1000.0f) * (float)FRAMERATE;

    LastTime = clock.getElapsedTime().asMilliseconds();

    Frames++;
}

int CFPS::GetFPS() {
    return NumFrames;
}

float CFPS::GetSpeedFactor() {
    return SpeedFactor;
}
