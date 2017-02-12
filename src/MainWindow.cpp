//
// Created by ondra on 13.2.17.
//

#include "MainWindow.h"

MainWindow::MainWindow() {
    window = NULL;
    content = NULL;
}

bool MainWindow::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    window = SDL_CreateWindow( "Vecto-Dyna", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (window == NULL) {
        return false;
    }

    content = SDL_GetWindowSurface( window );
    SDL_FillRect(content, NULL, SDL_MapRGB(content->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    return true;
}

MainWindow::~MainWindow() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
