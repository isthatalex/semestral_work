//
// Created by alexz on 5/6/18.
//

#ifndef SEMESTRAL_WORK_CENEMY_H
#define SEMESTRAL_WORK_CENEMY_H


#include "CMovingObject.h"

class CEnemy : public CMovingObject {
public:
    CEnemy(const char *textureName, int x, int y,
           int w, int h, int HP, int dmg, int HPMax, int dist);

    ~CEnemy() = default;

    virtual void move();

    virtual void update();

    virtual void collideWith(CHero &x);

    void takeDmg(int x);

    std::string save2String() const;

    static int cnt;
private:
    int m_Distance;
    int m_Start;
};


#endif //SEMESTRAL_WORK_CENEMY_H
