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
    ~CWall() = default;
    virtual void collideWith (CHero & x);
    std::string save2String() const;
    static int cnt;
};


#endif //SEMESTRAL_WORK_CWALL_H
