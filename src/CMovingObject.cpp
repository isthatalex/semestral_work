//
// Created by alexz on 5/5/18.
//

#include "CMovingObject.h"

CMovingObject::CMovingObject(const char *textureName, int x, int y, int w, int h) :
        CGameObject(textureName, x, y, w, h), m_xVel(0), m_yVel(0), m_HP(200), m_HPMax(m_HP), m_lvl(1)
{}

void CMovingObject::move() {
    const int step = 1;
    m_xPos+=m_xVel*step;
    m_yPos+=m_yVel*step;
}

void CMovingObject::update() {
    move();
    CGameObject::update();
}
