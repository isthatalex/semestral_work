//
// Created by alexz on 5/4/18.
//


#include "CGame.h"
#include "CTextureManager.h"
#include "CGameObject.h"

CGameObject * myPlayer, * myEnemy;

SDL_Renderer * CGame::myRenderer = NULL;
CGame::CGame() {

}

CGame::~CGame() {

}

void CGame::init(const char *title, int xpos, int ypos,
                 int width, int height, bool fullscreen){
    int windowFlags = 0;
    if (fullscreen){
        windowFlags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initialized..." << std::endl;
        myWindow = SDL_CreateWindow(title, xpos, ypos, width, height, windowFlags);

        if (myWindow){
            std::cout << "Window created..." << std::endl;
        }

        myRenderer = SDL_CreateRenderer(myWindow, -1, 0);
        if (myRenderer){
            SDL_SetRenderDrawColor(myRenderer, 255, 255, 255, 255);
            std::cout << "Renderer created..." << std::endl;
        }

        isRunning = true;

    }else{
        isRunning = false;
    }

   myPlayer = new CGameObject("cat.png", 0, 0);
    myEnemy = new CGameObject("enemy.png",  50, 50);
}

void CGame::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

//movement
void CGame::update() {
    myPlayer->update();
    myEnemy->update();
}

void CGame::render() {
    SDL_RenderClear(myRenderer);
    myPlayer->render();
    myEnemy->render();
    //adding stuff to render
    SDL_RenderPresent(myRenderer);
}

void CGame::clean() {
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}

bool CGame::running() {
    return isRunning;
}