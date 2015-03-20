#include "CApp.h"

#include <iostream>

void CApp::OnLoop() {
    CFPS::FPSControl.OnLoop();

    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

    CCamera::CameraControl.OnLoop();

    std::cout << "CCamera::CameraControl.GetX(): " << CCamera::CameraControl.GetX() << std::endl;
    std::cout << "CCamera::CameraControl.GetY(): " << CCamera::CameraControl.GetY() << std::endl;
    std::cout << "CCamera::CameraControl.GetX(): " << CCamera::CameraControl.GetX() << std::endl;
    std::cout << "Player.X: " << Player.X << std::endl;
    std::cout << "Player.Y: " << Player.Y << std::endl;
}
