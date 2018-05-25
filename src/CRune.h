//
// Created by alexz on 5/8/18.
//

#ifndef SEMESTRAL_WORK_CRUNE_H
#define SEMESTRAL_WORK_CRUNE_H

#include "CHero.h"

class CRune : public CGameObject{
public:
    CRune(const char * textureName, int x, int y, int w, int h, int type);
    virtual void collideWith (CHero & x);
private:
    int m_Type;
};


#endif //SEMESTRAL_WORK_CRUNE_H
