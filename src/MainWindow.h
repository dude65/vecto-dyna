//
// Created by ondra on 13.2.17.
//

#ifndef VECTO_DYNA_MAINWINDOW_H
#define VECTO_DYNA_MAINWINDOW_H


#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class MainWindow {
public:
    MainWindow();
    bool init();
    ~MainWindow();

private:
    SDL_Window * window;
    SDL_Surface * content;
};


#endif //VECTO_DYNA_MAINWINDOW_H
