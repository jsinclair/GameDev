#include "CApp.h"

CApp::CApp() {
    window = NULL;
    testTexture = NULL;

    running = true;
}

int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    sf::Event event;

    while(running) {
        while(window->pollEvent(event)) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}
