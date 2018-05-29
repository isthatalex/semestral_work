//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CGAME_H
#define SEMESTRAL_WORK_CGAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "CGameObject.h"
#include "CHero.h"
#include "CEnemy.h"
#include "CMap.h"
#include "CWall.h"
#include "CRune.h"
#include <SDL2/SDL_image.h>

class CMap;

class CGame {
public:
    CGame(SDL_Window *wind, SDL_Renderer *rend, std::string fileName, int heroSuperPower);

    ~CGame();

    void init();

    void handleEvents();

    void update();

    void render();

    void clean();

    bool loadGame(std::string fileName);

    bool saveGame(std::string fileName);

    bool running() const; // is the game running

    static SDL_Renderer *myRenderer;


private:
    bool isRunning;
    int playerSP;
    SDL_Window *myWindow;
    CHero *myPlayer;
    std::string fileName;
    CMap *myMap;
    std::vector<CGameObject *> m_Objects;

    bool checkCollision(const SDL_Rect &a, const SDL_Rect &b) const;

    bool checkCollisionHit(SDL_Rect &rect, SDL_Rect &sdl_rect) const;
};


#endif //SEMESTRAL_WORK_CGAME_H
