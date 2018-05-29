//
// Created by alexz on 5/4/18.
//

#include "CGame.h"
#include <algorithm>
#include <fstream>
#include <utility>


SDL_Renderer *CGame::myRenderer = NULL;

CGame::CGame(SDL_Window *wind, SDL_Renderer *rend, std::string file, int heroSuperPower) {
    std::cout << "Game created" << std::endl;
    myWindow = wind;
    myRenderer = rend;
    fileName = std::move(file);
    playerSP = heroSuperPower;
}

CGame::~CGame() {
    for (auto x = m_Objects.begin(); x != m_Objects.end(); ++x) {
        delete (*x);
    }
    m_Objects.clear();
    delete myPlayer;
    delete myMap;
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
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:

                    myPlayer->setxVel() = -1;
                    break;
                case SDLK_RIGHT:
                    myPlayer->setxVel() = 1;
                    break;
                case SDLK_UP:
                    myPlayer->setyVel() = -1;
                    break;
                case SDLK_DOWN:
                    myPlayer->setyVel() = 1;
                    break;
                case SDLK_0:
                    myPlayer->useHeal();
                    break;
                case SDLK_1:
                    myPlayer->useDD();
                    break;
                case SDLK_2:
                    myPlayer->useHaste();
                    break;
                case SDLK_x:
                    myPlayer->setHitAnimation() = 5;
                    break;
                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:

                    if (myPlayer->getxVel() < 0)
                        myPlayer->setxVel() = 0;
                    break;
                case SDLK_RIGHT:
                    if (myPlayer->getxVel() > 0)
                        myPlayer->setxVel() = 0;
                    break;
                case SDLK_UP:
                    if (myPlayer->getyVel() < 0)
                        myPlayer->setyVel() = 0;
                    break;
                case SDLK_DOWN:
                    if (myPlayer->getyVel() > 0)
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
            std::remove_if(m_Objects.begin(), m_Objects.end(), [&](CGameObject *entity) {
                return (entity->isDestroyed());
            }),
            m_Objects.end());
    for (auto x = m_Objects.begin(); x != m_Objects.end(); ++x) {
        if (checkCollision(myPlayer->getRect(), (*x)->getRect())) (*x)->collideWith(*myPlayer);
    }

    for (auto x = m_Objects.begin(); x != m_Objects.end(); ++x) {
        if (checkCollisionHit(myPlayer->getRect(), (*x)->getRect())) (*x)->takeDmg(myPlayer->getDMG());
    }


    myPlayer->update();
    for (auto x = m_Objects.begin(); x != m_Objects.end(); ++x) {
        (*x)->update();
    }
    if (myPlayer->getHP() <= 0) {
        std::cout << "GAME OVER!" << std::endl;
        SDL_Delay(3000);
        isRunning = false;
    }
}

void CGame::render() {
    SDL_RenderClear(myRenderer);
    myMap->DrawMap();
    myPlayer->render();

    for (auto x = m_Objects.begin(); x != m_Objects.end(); ++x) {
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
    return a.x + myPlayer->getxVel() + a.w > b.x &&
           a.y + myPlayer->getyVel() + a.h > b.y &&
           b.x + b.w > a.x + myPlayer->getxVel() &&
           b.y + b.h > a.y + myPlayer->getyVel();
}

bool CGame::loadGame(std::string fileName) {
    std::ifstream in(fileName, std::ios_base::in);
    if (in.fail()) return false;
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

    for (int k = 0; k < 8; ++k) in >> attributes[k];
    myPlayer = new CHero("../images/cat_startl.png", "../images/cat_startr.png", attributes[0], attributes[1],
                         attributes[2], attributes[3], attributes[4], attributes[5], attributes[6], attributes[7],
                         "../images/cat_right.png", "../images/cat.png");
    for (int k = 0; k < 3; ++k) in >> attributes[k];
    myPlayer->getInv().init(attributes[0], attributes[1], attributes[2]);
    switch (playerSP) {
        case 1:
            myPlayer->setHP() *= 2;
            myPlayer->setMaxHP() *= 2;
            break;
        case 2:
            myPlayer->setDMG() *= 2;
            break;
        case 3:
            myPlayer->setSpeed() *= 2;
            break;
        default:
            break;
    }

    in >> CEnemy::cnt;

    for (int l = 0; l < CEnemy::cnt; ++l) {
        for (int k = 0; k < 8; ++k) in >> attributes[k];
        m_Objects.push_back(new CEnemy("../images/enemy.png", attributes[0], attributes[1], attributes[2],
                                       attributes[3], attributes[4], attributes[5], attributes[6], attributes[7]));
    }
    in >> CRune::cnt;
    char fileRune[100];
    for (int l = 0; l < CRune::cnt; ++l) {
        for (int k = 0; k < 5; ++k) in >> attributes[k];
        switch (attributes[4]) {
            case 0:
                strcpy(fileRune, "../images/heal.png");
                break;
            case 1:
                strcpy(fileRune, "../images/doubledamage.png");
                break;
            case 2:
                strcpy(fileRune, "../images/haste.png");
                break;
            default:
                break;
        }
        m_Objects.push_back(new CRune(fileRune, attributes[0], attributes[1], attributes[2],
                                      attributes[3], attributes[4]));
    }
    in.close();
    return true;
}

bool CGame::saveGame(std::string fileName) {
    std::ofstream out(fileName, std::ios_base::out);
    if (out.fail()) return false;
    out << myMap->save2String();

    out << CWall::cnt << "\n";
    size_t l = 0;
    for (; l < (unsigned) CWall::cnt; ++l) {
        out << m_Objects[l]->save2String();
    }
    out << myPlayer->save2String();
    out << CEnemy::cnt << "\n";
    size_t limit = l + CEnemy::cnt;
    for (; l < limit; ++l) {
        out << m_Objects[l]->save2String();
    }
    out << CRune::cnt << "\n";
    limit += CRune::cnt;
    for (; l < limit && l < m_Objects.size(); ++l) {
        out << m_Objects[l]->save2String();
    }
    out.close();
    return true;
}

bool CGame::checkCollisionHit(SDL_Rect &a, SDL_Rect &b) const {
    SDL_Rect a1 = a;
    if (myPlayer->getHitAnimation() == 5 && myPlayer->getxVel() >= 0) {
        a1.x += 20;
        if (checkCollision(a1, b)) return true;
    } else if (myPlayer->getHitAnimation() == 5 && myPlayer->getxVel() < 0) {
        a1.x -= 20;
        if (checkCollision(a1, b)) return true;
    }
    return false;
}
