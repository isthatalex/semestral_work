//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CGAMEOBJECT_H
#define SEMESTRAL_WORK_CGAMEOBJECT_H
#include "SDL2/SDL.h"
//#include "CHero.h"
class CMovingObject;
class CHero;
class CGameObject {

public:
    CGameObject(const char * textureName, int x, int y, int w, int h);
    //~CGameObject();

    virtual void update();
    void render();
    SDL_Rect  getRect() const;
    SDL_Rect & getRect();
    virtual void collideWith (CHero & x) = 0;

protected:
    int m_xPos;
    int m_yPos;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture * m_ObjectTexture;


};


#endif //SEMESTRAL_WORK_CGAMEOBJECT_H
