#ifndef _CSKELETON_H_
    #define _CSKELETON_H_

#include "CNPC.h"
#include "CPlayer.h"

class CSkeleton : public CNPC {
    public:
        CSkeleton();

        CPlayer* owner;

        void OnLoop();

        void OnThink();

        void OnAnimate();
};

#endif
