//
// Created by alexz on 5/6/18.
//

#include "CHero.h"
#include "CGame.h"
#include "CTextureManager.h"
#include <iostream>
#include <cstdlib>
CHero::CHero(const char *textureName, const char * textureRight, int x, int y, int w, int h, int HP, int dmg, int HPMax,
const char *hitr, const char * hitl) :
        CMovingObject(textureName, x, y, w, h, HP, dmg, HPMax), hitAnimationCnt(0), m_Kills(0), m_speedConst(1),
            m_TextureRight (CTextureManager::LoadTexture(textureRight)),
        m_hitRight (CTextureManager::LoadTexture(hitr)),
        m_hitLeft (CTextureManager::LoadTexture(hitl)){

}

void CHero::update() {
    move();
    destRect.x = m_xPos;
    destRect.y = m_yPos;
    system("clear");
    std::cout << "\t0 - heal; 1 - DD; 2 - haste; X - hit" << std::endl;
    std::cout << "\tHP == " << m_HP  << "; dmg == " << m_dmg << "; speed == " <<
              ((abs(m_xVel) > abs(m_yVel))? m_xVel :m_yVel) << "\n\t" << getInv() << std::endl;
}


void CHero::move() {
    m_xPos+=m_xVel*m_speedConst;
    m_yPos+=m_yVel*m_speedConst;
}

void CHero::useHeal() {
    if(m_Runes.useHealing()) m_HP  = (m_HPMax > m_HP + 50) ? m_HP+50 : m_HPMax;
    else std::cout << "No heal runes available." << std::endl;
}

void CHero::useHaste() {
    if(m_Runes.useHaste()) {m_speedConst *=2;}
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
               + std::to_string(m_dmg) + " " + std::to_string(m_HPMax) + "\n" + m_Runes.save2String() + "\n";
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

