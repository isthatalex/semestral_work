//
// Created by alexz on 5/4/18.
//

#include "CGameObject.h"
#include <iostream>
#include "CTextureManager.h"
#include "CGame.h"

CGameObject::CGameObject(const char *textureName, int x, int y, int w, int h) : isAlive(true) {
    std::cout << "Created object from " << textureName << std::endl;

    m_ObjectTexture = CTextureManager::LoadTexture(textureName);
    m_xPos = x;
    m_yPos = y;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;

}

void CGameObject::update() {
    destRect.x = m_xPos;
    destRect.y = m_yPos;
}

void CGameObject::render() {
    SDL_RenderCopy(CGame::myRenderer, m_ObjectTexture, &srcRect, &destRect);
}


SDL_Rect &CGameObject::getRect() {
    return destRect;
}

CGameObject::~CGameObject() {
    SDL_DestroyTexture(m_ObjectTexture);

}


