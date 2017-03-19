//
// Created by ondra on 26.2.17.
//

#include "LButton.h"

LButton::LButton() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    buttonArea = NULL;
}

void LButton::handleEvent(SDL_Event &e) {
    //TODO
}

bool LButton::load(const std::string &text, const SDL_Color &color, SDL_Renderer *renderer) {
    fs::path envPath(getEnvironmentHome());
    fs::path fontPath(BUTTON_FONT);
    fs::path path = envPath / fontPath;

    font = TTF_OpenFont(fs::absolute(path).normalize().c_str(), BUTTON_FONT_SIZE);

    if (font == NULL) {
        return false;
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

    if (textSurface == NULL) {
        return false;
    }

    buttonArea = SDL_CreateTextureFromSurface(renderer, textSurface);

    if (buttonArea == NULL) {
        return false;
    }

    width = textSurface->w;
    height = textSurface->h;

    SDL_FreeSurface(textSurface);

    return true;
}

void LButton::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void LButton::setSize(int w, int h) {
    this->width = w;
    this->height = h;
}


void LButton::render(SDL_Renderer * renderer) {
    SDL_Rect area;
    area.x = x;
    area.y = y;
    area.w = width;
    area.h = height;
    SDL_RenderCopy(renderer, buttonArea, NULL, &area);
}

LButton::~LButton() {
    TTF_CloseFont(font);
    font = NULL;
}
