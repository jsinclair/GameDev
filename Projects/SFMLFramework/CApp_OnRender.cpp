#include "CApp.h"

void CApp::OnRender() {
    window->clear();

    CSurface::OnDraw(window, testTexture);

    window->display();
}
