//
// Created by alexz on 5/4/18.
//

#include "CGame.h"

int main(){
    CGame * game;

    const int FPS = 60;
    const int frameDelay = 500 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new CGame();
    game->init("KoilGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
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

    return 0;
}