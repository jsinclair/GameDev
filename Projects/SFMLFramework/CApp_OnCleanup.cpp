#include "CApp.h"

void CApp::OnCleanup() {
    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnCleanup();
    }

    CEntity::EntityList.clear();

    window->close();
}
