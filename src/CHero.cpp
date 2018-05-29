//
// Created by alexz on 5/6/18.
//

#include "CHero.h"
#include "CGame.h"
#include "CTextureManager.h"
#include <iostream>
#include <cstdlib>
CHero::CHero(const char *textureName, const char * textureRight, int x, int y, int w, int h, int HP, int dmg, int HPMax,
             int speed, const char *hitRight, const char * hitLeft) :
        CMovingObject(textureName, x, y, w, h, HP, dmg, HPMax), hitAnimationCnt(0), m_speedConst(speed),
        m_TextureRight (CTextureManager::LoadTexture(textureRight)), m_hitLeft (CTextureManager::LoadTexture(hitLeft)),
        m_hitRight (CTextureManager::LoadTexture(hitRight)){

}

CHero::~CHero() {
    SDL_DestroyTexture(m_TextureRight);
    SDL_DestroyTexture(m_hitLeft);
    SDL_DestroyTexture(m_hitRight);

}


void CHero::update() {
    this->move();
    destRect.x = m_xPos;
    destRect.y = m_yPos;
    system("clear");
    std::cout << "\t0 - heal; 1 - DD; 2 - haste; X - hit" << std::endl;
    std::cout << "\tHP == " << m_HP  << "; dmg == " << m_dmg << "; speed == " <<
              ((abs(m_xVel) > abs(m_yVel))? m_xVel*m_speedConst :m_yVel*m_speedConst) <<"\n\t" << getInv() << std::endl;
}


void CHero::move() {
    m_xPos+=m_xVel*m_speedConst;
    m_yPos+=m_yVel*m_speedConst;
}

void CHero::useHeal() {
    if(m_Runes.useHealing()) m_HP  = (m_HPMax > m_HP + 100) ? m_HP + 100 : m_HPMax;
    else std::cout << "No heal runes available." << std::endl;
}

void CHero::useHaste() {
    if(m_Runes.useHaste()) {m_speedConst *= 2;}
    else std::cout << "No haste runes available." << std::endl;
}

void CHero::useDD() {
    if(m_Runes.useDD()) m_dmg  += 50;
    else std::cout << "No double damage runes available." << std::endl;
}


void CHero::pickRune(int type) {
    switch (type){
        case 0 : m_Runes.getHealing(); break;
        case 1 : m_Runes.getDD(); break;
        case 2 : m_Runes.getHaste(); break;
        default : break;
    }
}

std::string  CHero::save2String() const {
    return     std::to_string(m_xPos) + " "  + std::to_string(m_yPos) + " " + std::to_string(destRect.w)
               + " " + std::to_string(destRect.h) + " " + std::to_string(m_HP) + " "
               + std::to_string(m_dmg) + " " + std::to_string(m_HPMax) + " " + std::to_string(m_speedConst)
               + "\n" + m_Runes.save2String() + "\n";
}

void CHero::render() {
    if (hitAnimationCnt > 0){

        if (m_xVel>=0)  SDL_RenderCopy(CGame::myRenderer, m_hitRight, &srcRect, &destRect);
        else  SDL_RenderCopy(CGame::myRenderer, m_hitLeft, &srcRect, &destRect);
        hitAnimationCnt--;
    }
    else {
        if (m_xVel>=0)  SDL_RenderCopy(CGame::myRenderer, m_TextureRight, &srcRect, &destRect);
        else  SDL_RenderCopy(CGame::myRenderer, m_ObjectTexture, &srcRect, &destRect);
    }
}

void CHero::takeDmg(int x) {
    m_HP -= x;
}

CInventory &CHero::getInv()  {
    return m_Runes;
}

