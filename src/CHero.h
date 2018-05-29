//
// Created by alexz on 5/6/18.
//

#ifndef SEMESTRAL_WORK_CHERO_H
#define SEMESTRAL_WORK_CHERO_H

#include "CMovingObject.h"
#include "CInventory.h"
#include "CEnemy.h"

class CHero : public CMovingObject {
public:
    CHero(const char *textureName, const char *textureRight, int x, int y,
          int w, int h, int HP, int dmg, int HPMax, int speed, const char *hitRight, const char *hitLeft);

    ~CHero();

    virtual void move();

    virtual void update();

    virtual void render();

    void useHeal();

    void useHaste();

    void useDD();

    CInventory &getInv();

    int &setSpeed() { return m_speedConst; }

    int &setDMG() { return m_dmg; }

    int &setHitAnimation() { return hitAnimationCnt; }

    int getHitAnimation() const { return hitAnimationCnt; }

    std::string save2String() const;

    void pickRune(int type);

    void takeDmg(int x);

private:
    int hitAnimationCnt;
    int m_speedConst;
    CInventory m_Runes;
    SDL_Texture *m_TextureRight;
    SDL_Texture *m_hitLeft;
    SDL_Texture *m_hitRight;


};


#endif //SEMESTRAL_WORK_CHERO_H
