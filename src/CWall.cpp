//
// Created by alexz on 5/8/18.
//

#include "CWall.h"
#include <iostream>
int CWall::cnt = 0;
CWall::CWall(const char *textureName, int x, int y, int w, int h) : CGameObject(textureName, x, y, w, h) {
}

void CWall::collideWith(CHero &x) {
    x.setxVel() = 0;
    x.setyVel() = 0;
    std::cout << "Collision wall!!!" << std::endl;
}

std::string CWall::save2String() const{
    return     std::to_string(m_xPos) + " "  + std::to_string(m_yPos) + " " + std::to_string(destRect.w)
               + " " + std::to_string(destRect.h) + "\n";
}

