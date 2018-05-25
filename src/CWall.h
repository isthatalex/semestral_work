//
// Created by alexz on 5/8/18.
//

#ifndef SEMESTRAL_WORK_CWALL_H
#define SEMESTRAL_WORK_CWALL_H


#include "CGameObject.h"
#include "CHero.h"

class CWall : public CGameObject{
public:
    CWall(const char * textureName, int x, int y, int w, int h);
    virtual void collideWith (CHero & x);
};


#endif //SEMESTRAL_WORK_CWALL_H
