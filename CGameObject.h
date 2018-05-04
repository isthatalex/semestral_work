//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CGAMEOBJECT_H
#define SEMESTRAL_WORK_CGAMEOBJECT_H
#include "SDL2/SDL.h"

class CGameObject {

public:
    CGameObject(const char * textureName, int x, int y);
    ~CGameObject();

    void update();
    void render();


private:
    int m_xPos;
    int m_yPos;

    SDL_Texture * m_ObjectTexture;
    SDL_Rect srcRect, destRect;

};


#endif //SEMESTRAL_WORK_CGAMEOBJECT_H
