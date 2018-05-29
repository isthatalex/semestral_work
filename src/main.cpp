//
// Created by alexz on 5/4/18.
//

#include "CGameEngine.h"

int main(){
    CGameEngine * gameEngine;
    gameEngine = new CGameEngine();
    gameEngine->init();
    gameEngine->gameLoop();
    delete gameEngine;
    return 0;
}