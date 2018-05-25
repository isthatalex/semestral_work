//
// Created by alexz on 5/6/18.
//

#include "CEnemy.h"
#include "CHero.h"
#include <iostream>
CEnemy::CEnemy(const char *textureName, int x, int y, int w, int h, int HP, int dmg) :
        CMovingObject(textureName, x, y, w, h, HP, dmg) {

}

void CEnemy::update() {
    move();
    destRect.x = m_xPos;
    destRect.y = m_yPos;
}


void CEnemy::move() {

}

void CEnemy::collideWith(CHero &x) {
    x.setxVel() = 0;
    x.setyVel() = 0;
    x.setHP() -= this->getDMG();
    std::cout << "Collision enemy!!! HP ==" << x.getHP() << std::endl;

}
