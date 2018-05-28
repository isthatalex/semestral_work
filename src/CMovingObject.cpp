//
// Created by alexz on 5/5/18.
//

#include "CMovingObject.h"

CMovingObject::CMovingObject(const char *textureName, int x, int y, int w, int h, int HP, int dmg, int HPMax) :
        CGameObject(textureName, x, y, w, h), m_xVel(0), m_yVel(0), m_HP(HP), m_HPMax(HPMax), m_dmg(dmg)
{}




int CMovingObject::getyVel() const {
    return m_yVel;
}

int CMovingObject::getxVel() const{
    return m_xVel;
}


int & CMovingObject::setyVel(){
    return m_yVel;
}

int & CMovingObject::setxVel(){
    return m_xVel;
}

int &CMovingObject::setHP() {
    return m_HP;
}

int CMovingObject::getHP() const {
    return m_HP;
}

int CMovingObject::getDMG() const {
    return m_dmg;
}
