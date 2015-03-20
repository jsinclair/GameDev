#include "CApp.h"

void CApp::OnRender() {
    window->clear();

    CTexture::OnDraw(window, testTexture, 0, 0);

    CTexture::OnDraw(window, testTexture, 0, 0, 91, 9, 527, 392);

    CArea::AreaControl.OnRender(window, CCamera::CameraControl.GetX(), CCamera::CameraControl.GetY());

    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender(window);
    }

    window->display();
}
