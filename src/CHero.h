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
    CHero(const char * textureName, const char * textureRight, int x, int y,
                  int w, int h, int HP, int dmg, int HPMax, const char * hitr, const char* hitl);
    ~CHero() = default;
    virtual void move();
    virtual void update();

    void useHeal();
    void useHaste();
    void useDD();
    CInventory & getInv () {
        return m_Runes;
    }
    std::string save2String () const;
    void pickRune (int type);
    void render ();
    virtual void collideWith(CHero & x) {}
    int hitAnimationCnt;
private:
    int m_Kills;
    int m_speedConst;
    CInventory m_Runes;
    SDL_Texture * m_TextureRight;
    SDL_Texture * m_hitLeft;
    SDL_Texture * m_hitRight;


};


#endif //SEMESTRAL_WORK_CHERO_H
