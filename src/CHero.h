//
// Created by alexz on 5/6/18.
//

#ifndef SEMESTRAL_WORK_CHERO_H
#define SEMESTRAL_WORK_CHERO_H
#include "CMovingObject.h"
#include "CInventory.h"
#include "CEnemy.h"

class CHero : public CMovingObject{
public:
    CHero(const char * textureName, int x, int y,
                  int w, int h, int HP, int dmg);

    virtual void move();
    virtual void update();
    void useHeal();
    void useHaste();
    void useInvulnerability();
    void hit (CEnemy & x) const;
    void pickRune (int type);
    virtual void collideWith(CHero & x) {}

private:
    int m_Kills;
    CInventory m_Runes;

};


#endif //SEMESTRAL_WORK_CHERO_H
