//
// Created by alexz on 5/6/18.
//

#include "CEnemy.h"
#include "CHero.h"
#include <iostream>
int CEnemy::cnt = 0;
CEnemy::CEnemy(const char *textureName, int x, int y, int w, int h, int HP, int dmg, int HPMax, int dist) :
        CMovingObject(textureName, x, y, w, h, HP, dmg, HPMax), m_Distance(dist), m_Start (m_xPos){
    if (m_Distance >= 0) m_xVel = 1;
    else m_xVel = -1;
}

void CEnemy::update() {
    move();
    destRect.x = m_xPos;
    destRect.y = m_yPos;
}


void CEnemy::move() {
    if (m_xPos - m_Start == m_Distance){
        m_Distance = -m_Distance;
        m_xVel = -m_xVel;
    }
    m_xPos += m_xVel;


}

void CEnemy::collideWith(CHero &x) {
    x.setxVel() = 0;
    x.setyVel() = 0;
    x.takeDmg(this->getDMG());
    std::cout << "Collision enemy!!! HP == " << x.getHP() << std::endl;

}

std::string CEnemy::save2String() const {
    return     std::to_string(m_xPos) + " "  + std::to_string(m_yPos) + " " + std::to_string(destRect.w)
               + " " + std::to_string(destRect.h) + " " + std::to_string(m_HP) + " "
               + std::to_string(m_dmg) + " " + std::to_string(m_HPMax) + " " + std::to_string(m_Distance) + "\n";
}

void CEnemy::takeDmg(int x) {
    m_HP -= x;
    if (m_HP <= 0) {
            this->isAlive = false;
        CEnemy::cnt --;
    }
}


