//
// Created by ondra on 13.2.17.
//

#include <iostream>
#include "MainWindow.h"

const static int SCREEN_WIDTH = 640;
const static int SCREEN_HEIGHT = 480;
const static char * SCREEN_TITLE = "Vecto-dyna";

const static int BUTTON_WIDTH = 76;
const static int BUTTON_HEIGHT = 26;
const static int BUTTON_SPACE = 6;

const static std::string NEW_GAME_BUTTON = "New game";
const static std::string LOAD_GAME_BUTTON = "Load game";
const static std::string QUIT_BUTTON = "Quit";


MainWindow::MainWindow() {
    alive = true;
    window = NULL;
    content = NULL;
}

bool MainWindow::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    if (TTF_Init() == -1) {
        return false;
    }

    window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (window == NULL) {
        return false;
    }

    content = SDL_GetWindowSurface(window);
    SDL_FillRect(content, NULL, SDL_MapRGB(content->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    renderer = SDL_GetRenderer(window);

    if (renderer == NULL) {
        return false;
    }

    loadContent();


    SDL_RenderPresent(renderer);
    return renderer != NULL;
}

bool MainWindow::loadContent() {
    SDL_Color color;
    color.a = 0;
    color.r = 255;
    color.g = 0;
    color.b = 0;

    LButton * newGameButton = loadButton(NEW_GAME_BUTTON, color);

    if (newGameButton == NULL) {
        return false;
    }

    LButton * loadGameButton = loadButton(LOAD_GAME_BUTTON, color);

    if (loadGameButton == NULL) {
        return false;
    }

    LButton * quitButton = loadButton(QUIT_BUTTON, color);

    if (quitButton == NULL) {
        return false;
    }

    renderButtons();

    return true;
}

LButton* MainWindow::loadButton(const std::string &name, const SDL_Color &color) {
    LButton * button = new LButton();
    bool success = button->load(name, color, renderer);

    if (!success) {
        delete button;
        return NULL;
    }

    buttons.push_back(button);

    return button;
}

void MainWindow::renderButtons() {
    int cnt = (int) buttons.size();

    int x = SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2;
    int y = SCREEN_HEIGHT / 2 - (cnt * (BUTTON_HEIGHT + BUTTON_SPACE)) / 2;

    for (auto button : buttons) {
        button->setPosition(x, y);
        button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);

        button->render(renderer);

        y += BUTTON_SPACE + BUTTON_HEIGHT;
    }
}

void MainWindow::run() {
    SDL_Event e;

    while (alive) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                alive = false;
            }
        }

        int wait = SDL_WaitEvent(&e);
        if (wait == 0) {
            return;
        }
    }
}

MainWindow::~MainWindow() {
    for (auto button : buttons) {
        delete button;
    }

    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
