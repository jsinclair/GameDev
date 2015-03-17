#include "CApp.h"

void CApp::OnRender() {
    window->clear();

    CSurface::OnDraw(window, testTexture, 0, 0);

    CSurface::OnDraw(window, testTexture, 0, 0, 91, 9, 527, 392);

    window->display();
}
