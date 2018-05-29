//
// Created by alexz on 5/27/18.
//

#ifndef SEMESTRAL_WORK_CGAMEENGINE_H
#define SEMESTRAL_WORK_CGAMEENGINE_H


#include "CGame.h"
#include "CMenu.h"

class CGameEngine {
public:

    ~CGameEngine();
    void init();
    void gameLoop();


private:
    SDL_Window * myWindow;
    SDL_Renderer * myRenderer;
    CGame * game;
    CMenu * menu;
    std::string fileName;

};


#endif //SEMESTRAL_WORK_CGAMEENGINE_H
