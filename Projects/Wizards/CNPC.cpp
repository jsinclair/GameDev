#include "CNPC.h"

#include <iostream>

CNPC::CNPC() {
}

void CNPC::OnLoop() {
    CNPC::OnThink();

    CEntity::OnLoop();
}

void CNPC::OnThink() {
    std::cout << "Thinking!" << std::endl;
}
