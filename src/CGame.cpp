//
// Created by alexz on 5/4/18.
//


#include "CGame.h"
#include "CGameObject.h"
#include "CMovingObject.h"
#include "CMap.h"

CMovingObject *myPlayer, *myEnemy;
CGameObject * myWall;
CMap *myMap;

SDL_Renderer *CGame::myRenderer = NULL;

CGame::CGame() {

}

CGame::~CGame() {

}

void CGame::init(const char *title, int xpos, int ypos,
                 int width, int height, bool fullscreen) {
    int windowFlags = 0;
    if (fullscreen) {
        windowFlags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized..." << std::endl;
        myWindow = SDL_CreateWindow(title, xpos, ypos, width, height, windowFlags);

        if (myWindow) {
            std::cout << "Window created..." << std::endl;
        }

        myRenderer = SDL_CreateRenderer(myWindow, -1, 0);
        if (myRenderer) {
            SDL_SetRenderDrawColor(myRenderer, 255, 255, 255, 255);
            std::cout << "Renderer created..." << std::endl;
        }

        isRunning = true;

    } else {
        isRunning = false;
    }

    myPlayer = new CMovingObject("../images/cat.png", 0, 0, 100, 100);
   // myEnemy = new CMovingObject("../images/enemy.png", 50, 50, 32, 32);
    myWall = new CGameObject("../images/wall.png", 200, 200, 32, 250);
    myMap = new CMap();
}

void CGame::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:

                    myPlayer->m_xVel = -1;
                    break;
                case SDLK_RIGHT:
                    myPlayer->m_xVel =  1;
                    break;
                case SDLK_UP:
                    myPlayer->m_yVel = -1;
                    break;
                case SDLK_DOWN:
                    myPlayer->m_yVel =  1;
                    break;
                default:
                    break;
            }
            break;
            /* We must also use the SDL_KEYUP events to zero the x */
            /* and y velocity variables. But we must also be       */
            /* careful not to zero the velocities when we shouldn't*/
        case SDL_KEYUP:
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:
                    /* We check to make sure the alien is moving */
                    /* to the left. If it is then we zero the    */
                    /* velocity. If the alien is moving to the   */
                    /* right then the right key is still press   */
                    /* so we don't touch the velocity            */
                    if( myPlayer->m_xVel < 0 )
                        myPlayer->m_xVel = 0;
                    break;
                case SDLK_RIGHT:
                    if( myPlayer->m_xVel > 0 )
                        myPlayer->m_xVel = 0;
                    break;
                case SDLK_UP:
                    if( myPlayer->m_yVel < 0 )
                        myPlayer->m_yVel = 0;
                    break;
                case SDLK_DOWN:
                    if( myPlayer->m_yVel > 0 )
                        myPlayer->m_yVel = 0;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

//movement
void CGame::update() {
    std:: cout << myPlayer->m_xVel << " -- " << myPlayer->m_yVel << std::endl;
    checkCollision(myPlayer->destRect, myWall->destRect);
    myPlayer->update();
    myWall->update();

    //myEnemy->update();
    //myMap->LoadMap();
}

void CGame::render() {
    SDL_RenderClear(myRenderer);
    myMap->DrawMap();
    myPlayer->render();
    //myEnemy->render();
    myWall->render();
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

bool CGame::checkCollision(const SDL_Rect &a, const SDL_Rect &b) {
    if(
        a.x + myPlayer->m_xVel + a.w >= b.x &&
        a.y + myPlayer->m_yVel + a.h >= b.y &&
        b.x + b.w >= a.x + myPlayer->m_xVel &&
        b.y + b.h >= a.y + myPlayer->m_yVel
            ) {
        myPlayer->m_xVel = 0;
        myPlayer->m_yVel = 0;
        std::cout << "Koilission!" << std::endl;
        return true;
    }
    return false;
}
