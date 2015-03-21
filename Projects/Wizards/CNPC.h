#ifndef _CNPC_H_
    #define _CNPC_H_

#include "CEntity.h"

class CNPC : public CEntity {
    public:
        virtual void OnLoop() = 0;

        virtual void OnThink() = 0;

        virtual void OnAnimate() = 0;
};

#endif
