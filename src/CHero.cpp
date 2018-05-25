//
// Created by alexz on 5/6/18.
//

#include "CHero.h"
#include <iostream>
CHero::CHero(const char *textureName, int x, int y, int w, int h, int HP, int dmg) :
        CMovingObject(textureName, x, y, w, h, HP, dmg), m_Kills(0) {

}

void CHero::update() {
    move();
    destRect.x = m_xPos;
    destRect.y = m_yPos;
}


void CHero::move() {
    m_xPos+=m_xVel;
    m_yPos+=m_yVel;
}

void CHero::useHeal() {
    if(m_Runes.useHealing()) m_HP  = (m_HPMax > m_HP + 50) ? m_HP+50 : m_HPMax;
    else std::cout << "No heal runes available." << std::endl;
}

void CHero::useHaste() {

}

void CHero::useInvulnerability() {

}

void CHero::hit(CEnemy & x) const {
    x.setHP() -= m_dmg;
}

void CHero::pickRune(int type) {
    switch (type){
        case 0 : m_Runes.getHealing(); break;
        case 1 : m_Runes.getHaste(); break;
        case 2 : m_Runes.getInvulnerability(); break;
        default : break;
    }
}

