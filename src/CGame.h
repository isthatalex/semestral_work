//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CGAME_H
#define SEMESTRAL_WORK_CGAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL_image.h>
#include "CGameObject.h"
#include "CHero.h"
#include "CMap.h"
class CMap;

class CGame {
public:
    CGame();
    ~CGame();

    void init (const char* title, int xpos, int ypos,
                int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool loadGame(const char * fileName);
    bool saveGame(const char * fileName);
    bool running () const; // is the game running

    static SDL_Renderer * myRenderer;

    bool checkCollision(const SDL_Rect & a, const SDL_Rect & b) const;

private:
    bool isRunning;
    SDL_Window * myWindow;
    CHero * myPlayer;
    int enemyCnt;
    CMap *myMap;
    std::vector <CGameObject * > m_Objects;

};


#endif //SEMESTRAL_WORK_CGAME_H
