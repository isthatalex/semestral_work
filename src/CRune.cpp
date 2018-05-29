//
// Created by alexz on 5/8/18.
//

#include "CRune.h"
#include <iostream>

int CRune::cnt = 0;

CRune::CRune(const char *textureName, int x, int y, int w, int h, int type) : CGameObject(textureName, x, y, w, h),
                                                                              m_Type(type) {
}

void CRune::collideWith(CHero &x) {
    x.pickRune(m_Type);
    isAlive = false;
    std::cout << "Collision rune!!!" << std::endl;
    cnt--;
}

std::string CRune::save2String() const {
    return std::to_string(m_xPos) + " " + std::to_string(m_yPos) + " " + std::to_string(destRect.w)
           + " " + std::to_string(destRect.h) + " " + std::to_string(m_Type) + "\n";
}
