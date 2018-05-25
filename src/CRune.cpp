//
// Created by alexz on 5/8/18.
//

#include "CRune.h"

#include <iostream>

CRune::CRune(const char *textureName, int x, int y, int w, int h, int type) : CGameObject(textureName, x, y, w, h), m_Type(type) {

}

void CRune::collideWith(CHero &x) {
    x.pickRune(m_Type);

    std::cout << "Collision rune!!!" << std::endl;
}
