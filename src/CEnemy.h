//
// Created by alexz on 5/6/18.
//

#ifndef SEMESTRAL_WORK_CENEMY_H
#define SEMESTRAL_WORK_CENEMY_H


#include "CMovingObject.h"

class CEnemy : public CMovingObject{
 public:
    CEnemy(const char * textureName, int x, int y,
          int w, int h, int HP, int dmg);

    virtual void move();
    virtual void update();
    virtual void collideWith (CHero & x);

};


#endif //SEMESTRAL_WORK_CENEMY_H
