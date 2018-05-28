//
// Created by alexz on 5/4/18.
//

#include "CGame.h"
#include <algorithm>
#include <fstream>
#include <utility>


SDL_Renderer *CGame::myRenderer = NULL;

CGame::CGame(SDL_Window * wind, SDL_Renderer * rend, std::string file) {
    std::cout << "Game created" << std::endl;
    myWindow = wind;
    myRenderer = rend;
    fileName = std::move(file);
}

CGame::~CGame() {

}

void CGame::init() {
    isRunning = true;
    myMap = new CMap();
    loadGame(fileName);



}

void CGame::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            saveGame("../images/savedGame.txt");
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
                case SDLK_0:
                    myPlayer->useHeal();
                case SDLK_1:
                    myPlayer->useDD();
                case SDLK_2:
                    myPlayer->useHaste();
                case SDLK_x:
                    myPlayer->hitAnimationCnt = 5;
                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:

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
    m_Objects.erase(
            std::remove_if(m_Objects.begin(), m_Objects.end(), [&](CGameObject* entity) {
                return (entity->isDestroyed()); }),
            m_Objects.end());
    for (std::vector<CGameObject*>::iterator x = m_Objects.begin(); x!= m_Objects.end(); ++x){
        if (checkCollision(myPlayer->getRect(), (*x)->getRect())) (*x)->collideWith(*myPlayer);
    }

    for (std::vector<CGameObject*>::iterator x = m_Objects.begin() + CWall::cnt; x!= m_Objects.begin()+ CWall::cnt +
                                                                                             CEnemy::cnt; ++x){
        if (checkCollisionHit(myPlayer->getRect(), (*x)->getRect())) (*x)->takeDmg(myPlayer->getDMG());
    }


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

bool CGame::loadGame(std::string fileName) {
    std::ifstream in(fileName, std::ios_base::in);
    int map[20][25];
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 25; ++j) {
            in >> map[i][j];
        }
    myMap->LoadMap(map);
    int attributes[8];
    in >> CWall::cnt;
    for (int l = 0; l < CWall::cnt; ++l) {
        for (int k = 0; k < 4; ++k) in >> attributes[k];
        m_Objects.push_back(new CWall("../images/wall.png", attributes[0], attributes[1], attributes[2],
                                      attributes[3]));
    }

    for (int k = 0; k < 7; ++k) in >> attributes[k];
    myPlayer = new CHero("../images/cat_startl.png", "../images/cat_startr.png", attributes[0], attributes[1],
                         attributes[2], attributes[3], attributes[4], attributes[5], attributes[6],
                         "../images/cat_right.png", "../images/cat.png");
    for (int k = 0; k < 3; ++k) in >> attributes[k];
    myPlayer->getInv().init(attributes[0],attributes[1], attributes[2]);

        in >> CEnemy::cnt;
        for (int l = 0; l < CEnemy::cnt; ++l) {
            for (int k = 0; k < 8; ++k) in >> attributes[k];
            m_Objects.push_back(new CEnemy("../images/enemy.png", attributes[0], attributes[1], attributes[2],
                                           attributes[3], attributes[4], attributes[5], attributes[6], attributes[7]));
        }
    in >> CRune::cnt;
    for (int l = 0; l < CRune::cnt; ++l) {
        for (int k = 0; k < 5; ++k) in >> attributes[k];
        m_Objects.push_back(new CRune("../images/water.png", attributes[0], attributes[1], attributes[2],
                                        attributes[3], attributes[4]));
    }
    in.close();
}

bool CGame::saveGame(std::string fileName) {
    std::ofstream out(fileName, std::ios_base::out);
    out << myMap->save2String();

    out << CWall::cnt << "\n";
    int l = 0;
    for (; l < CWall::cnt; ++l) {
        out << m_Objects[l]->save2String();
    }
    out << myPlayer->save2String();
    out << CEnemy::cnt << "\n";
    int limit = l + CEnemy::cnt;
    for (; l < limit; ++l) {
        out << m_Objects[l]->save2String();
    }
    out << CRune::cnt << "\n";
    limit += CRune::cnt;
    for (; l < limit && l < m_Objects.size(); ++l) {
        out << m_Objects[l]->save2String();
    }
    out.close();
}

bool CGame::checkCollisionHit(SDL_Rect &a, SDL_Rect &b) {
    if (myPlayer -> hitAnimationCnt > 0 && myPlayer->getxVel() >= 0){
        if (a.x + myPlayer->getxVel() + a.w + 20 > b.x &&
            a.y + myPlayer->getyVel() + a.h > b.y &&
            b.x + b.w > a.x + myPlayer->getxVel() + 20 &&
            b.y + b.h > a.y + myPlayer->getyVel()) return true;
    }
    else if (myPlayer -> hitAnimationCnt > 0 && myPlayer->getxVel() < 0){
        if (a.x + myPlayer->getxVel() + a.w - 20 > b.x &&
            a.y + myPlayer->getyVel() + a.h > b.y &&
            b.x + b.w > a.x + myPlayer->getxVel() - 20 &&
            b.y + b.h > a.y + myPlayer->getyVel()) return true;
    }
    return false;
}
