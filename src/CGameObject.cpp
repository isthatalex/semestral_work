//
// Created by alexz on 5/4/18.
//

#include "CGameObject.h"
#include <iostream>
#include "CTextureManager.h"
#include "CGame.h"

CGameObject::CGameObject(const char *textureName, int x, int y, int w, int h) {
    std::cout << "Created object from " << textureName << std::endl;

    m_ObjectTexture = CTextureManager::LoadTexture(textureName);
    m_xPos = x;
    m_yPos = y;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.w = w;
    destRect.h = h;


}

void CGameObject::update (){
  //  m_xPos ++;
  //  m_yPos ++;

    destRect.x = m_xPos;
    destRect.y = m_yPos;


}

void CGameObject::render() {
    SDL_RenderCopy(CGame::myRenderer, m_ObjectTexture, &srcRect, &destRect);
}


