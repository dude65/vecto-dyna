//
// Created by ondra on 13.2.17.
//

#include <iostream>
#include "MainWindow.h"

using namespace std;

int main(int argc, char ** argv) {
    MainWindow window;
    bool initiated = window.init();

    if (!initiated) {
        cerr << "Cannot initiate SDL window:" << endl;
        cerr << SDL_GetError() << endl;

        return 1;
    }

    window.run();

    return 0;
}