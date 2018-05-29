//
// Created by alexz on 5/5/18.
//

#ifndef SEMESTRAL_WORK_CMOVINGOBJECT_H
#define SEMESTRAL_WORK_CMOVINGOBJECT_H

#include "CGameObject.h"
#include <string>

class CHero;

class CMovingObject : public CGameObject {
public:
    CMovingObject(const char *textureName, int x, int y,
                  int w, int h, int HP, int dmg, int HPMax);

    ~CMovingObject() = default;

    virtual void move() = 0;

    virtual void update() = 0;

    int getxVel() const;

    int getyVel() const;

    int getHP() const;

    int getDMG() const;

    int &setxVel();

    int &setyVel();

    int &setHP();

    int &setMaxHP();


    virtual void collideWith(CHero &x) {}

    std::string save2String() const = 0;

protected:
    int m_xVel;
    int m_yVel;
    int m_HP;
    int m_HPMax;
    int m_dmg;


};


#endif //SEMESTRAL_WORK_CMOVINGOBJECT_H

