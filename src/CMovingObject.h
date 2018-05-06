//
// Created by alexz on 5/5/18.
//

#ifndef SEMESTRAL_WORK_CMOVINGOBJECT_H
#define SEMESTRAL_WORK_CMOVINGOBJECT_H

#include "CGameObject.h"
#include "IMovable.h"
#include <string>

class CMovingObject : public CGameObject, IMovable{
public:
    CMovingObject(const char * textureName, int x, int y,
                  int w, int h);



    virtual void move();
    virtual void update();
    int m_xVel;
    int m_yVel;
    int m_HP;
    int m_HPMax;
    int m_lvl;
    std::string m_Name;


};


#endif //SEMESTRAL_WORK_CMOVINGOBJECT_H
