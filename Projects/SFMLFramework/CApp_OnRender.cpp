#include "CApp.h"

void CApp::OnRender() {
    window->clear();

    CTexture::OnDraw(window, testTexture, 0, 0);

    CTexture::OnDraw(window, testTexture, 0, 0, 91, 9, 527, 392);

    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender(window);
    }

    window->display();
}
