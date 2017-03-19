//
// Created by ondra on 26.2.17.
//

#ifndef VECTO_DYNA_LBUTTON_H
#define VECTO_DYNA_LBUTTON_H

#include <string>
#include <SDL.h>
#include <boost/filesystem.hpp>
#include <SDL/SDL_ttf.h>
#include "Utilities.h"

const std::string BUTTON_FONT = "fonts/freefonts/FreeSerifBold.ttf";
const int BUTTON_FONT_SIZE = 26;

namespace fs = boost::filesystem;

class LButton {
public:
    LButton();

    bool load(const std::string &text, const SDL_Color &color, SDL_Renderer *renderer);
    void handleEvent(SDL_Event & e);
    void setPosition(int x, int y);
    void setSize(int w, int h);
    void render(SDL_Renderer * renderer);

    ~LButton();

private:
    int x, y;
    int width, height;
    SDL_Texture * buttonArea;
    TTF_Font * font;
};


#endif //VECTO_DYNA_LBUTTON_H
