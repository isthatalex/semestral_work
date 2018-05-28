//
// Created by alexz on 5/4/18.
//

#include "CTextureManager.h"
#include "CGame.h"

SDL_Texture * CTextureManager::LoadTexture(const char *fileName) {

    SDL_Surface * surface = IMG_Load(fileName);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(CGame::myRenderer, surface);
    SDL_FreeSurface(surface);

    return texture;

}

void CTextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {

    SDL_RenderCopy(CGame::myRenderer, tex, &src, &dest);
}
