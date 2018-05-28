//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CGAMEOBJECT_H
#define SEMESTRAL_WORK_CGAMEOBJECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>


class CMovingObject;
class CHero;
class CGameObject {

public:
    CGameObject(const char * textureName, int x, int y, int w, int h);
    virtual ~CGameObject();

    virtual void update();

    virtual void render();
    SDL_Rect  getRect() const;
    SDL_Rect & getRect();
    virtual void takeDmg(int x) {}
    bool isDestroyed () const { return !isAlive;}
    virtual void collideWith (CHero & x) = 0;
    virtual std::string save2String () const = 0;

protected:
    int m_xPos;
    int m_yPos;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture * m_ObjectTexture;
    bool isAlive;

};


#endif //SEMESTRAL_WORK_CGAMEOBJECT_H
