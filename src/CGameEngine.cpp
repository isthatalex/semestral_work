//
// Created by alexz on 5/27/18.
//

#include "CGameEngine.h"


void CGameEngine::init() {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized..." << std::endl;
        myWindow = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

        if (myWindow) {
            std::cout << "Window created..." << std::endl;
        }

        myRenderer = SDL_CreateRenderer(myWindow, -1, 0);
        if (myRenderer) {
            SDL_SetRenderDrawColor(myRenderer, 255, 255, 255, 255);
            std::cout << "Renderer created..." << std::endl;
        }


    } else {
       std::cout << "OWIBKA" << std::endl;
        exit(0);
    }
    menu = new CMenu();
    menu->init();
    std::cout << "Press ENTER to start a new game or type the game's filename and press ENTER" << std::endl;
    std::string fileName;
    if(std::cin.peek()=='\n') {
        std::cout << "NewGAME" << std::endl;
        game = new CGame(myWindow, myRenderer);
    }
    else{
        getline(std::cin, fileName);
        std::cout << fileName << std::endl;
        game = new CGame(myWindow, myRenderer, "../images/"+fileName);
    }


}

void CGameEngine::gameLoop() {
    const int FPS = 30;
    const int frameDelay = 500 / FPS;

    Uint32 frameStart;
    int frameTime;
    game->init();
    while (game->running()){


        frameStart = SDL_GetTicks();


        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        //need to delay
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
}
