//
// Created by alexz on 5/4/18.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CGame.h"
#include "CGameObject.h"
#include "CHero.h"
#include "CEnemy.h"
#include "CMap.h"
#include "CWall.h"



SDL_Renderer *CGame::myRenderer = NULL;

CGame::CGame() {
    std::cout << "Game created" << std::endl;
    enemyCnt = 0;
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

    myMap = new CMap();
    myPlayer = new CHero("../images/cat.png", 0, 0, 96, 96, 200, 20);
    m_Objects.push_back(new CEnemy("../images/enemy.png", 450, 450, 96, 96, 100, 50));
    enemyCnt++;
    m_Objects.push_back(new CWall("../images/wall.png", 200, 200, 32, 250));

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

                    myPlayer->setxVel() = -1;
                    break;
                case SDLK_RIGHT:
                    myPlayer->setxVel() =  1;
                    break;
                case SDLK_UP:
                    myPlayer->setyVel() = -1;
                    break;
                case SDLK_DOWN:
                    myPlayer->setyVel() =  1;
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
                    if( myPlayer->getxVel() < 0 )
                        myPlayer->setxVel() = 0;
                    break;
                case SDLK_RIGHT:
                    if( myPlayer->getxVel() > 0 )
                        myPlayer->setxVel() = 0;
                    break;
                case SDLK_UP:
                    if( myPlayer->getyVel() < 0 )
                        myPlayer->setyVel() = 0;
                    break;
                case SDLK_DOWN:
                    if( myPlayer->getyVel() > 0 )
                        myPlayer->setyVel() = 0;
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

    for (std::vector<CGameObject*>::iterator x = m_Objects.begin(); x!= m_Objects.end(); ++x){
        if (checkCollision(myPlayer->getRect(), (*x)->getRect())) (*x)->collideWith(*myPlayer);
    }

    /*if (checkCollision(myPlayer->getRect(), myWall->getRect())){
        myPlayer->setxVel() = 0;
        myPlayer->setyVel() = 0;
        std::cout << "Collision wall!!!" << std::endl;
    }
    if (checkCollision(myPlayer->getRect(), myEnemy->getRect())){
        myPlayer->setxVel() = 0;
        myPlayer->setyVel() = 0;
        myPlayer->setHP() -= myEnemy->getDMG();
        std::cout << "Collision enemy!!! HP ==" << myPlayer->getHP() << std::endl;
    }*/
    myPlayer->update();
    for (std::vector<CGameObject*>::iterator x = m_Objects.begin(); x!= m_Objects.end(); ++x){
        (*x)->update();
    }
    if (myPlayer->getHP() <= 0) {
        std::cout << "GAME OVER!" << std::endl;
        SDL_Delay(3000);
        isRunning = false;
    }
    //myMap->LoadMap();
}

void CGame::render() {
    SDL_RenderClear(myRenderer);
    myMap->DrawMap();
    myPlayer->render();

    for (std::vector<CGameObject*>::iterator x = m_Objects.begin(); x!= m_Objects.end(); ++x){
        (*x)->render();
    }
    //adding stuff to render
    SDL_RenderPresent(myRenderer);
}

void CGame::clean() {
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}

bool CGame::running() const {
    return isRunning;
}

bool CGame::checkCollision(const SDL_Rect &a, const SDL_Rect &b) const {
    if(
        a.x + myPlayer->getxVel() + a.w > b.x &&
        a.y + myPlayer->getyVel() + a.h > b.y &&
        b.x + b.w > a.x + myPlayer->getxVel() &&
        b.y + b.h > a.y + myPlayer->getyVel()
            ) {
        return true;
    }
    return false;
}

bool CGame::loadGame(const char *fileName) {
    return false;
}

bool CGame::saveGame(const char *fileName) {
    return false;
}
