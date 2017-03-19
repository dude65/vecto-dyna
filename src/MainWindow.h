//
// Created by ondra on 13.2.17.
//

#ifndef VECTO_DYNA_MAINWINDOW_H
#define VECTO_DYNA_MAINWINDOW_H


#include <SDL.h>
#include <SDL_ttf.h>
#include <list>
#include "LButton.h"

class MainWindow {
public:
    MainWindow();
    bool init();
    void run();
    ~MainWindow();

private:
    bool alive;
    SDL_Window * window;
    SDL_Surface * content;
    SDL_Renderer * renderer;

    bool loadContent();
    LButton * loadButton(const std::string &name, const SDL_Color &color);
    void renderButtons();

    std::list<LButton*> buttons;
};

#endif //VECTO_DYNA_MAINWINDOW_H
