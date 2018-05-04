//
// Created by alexz on 5/4/18.
//

#include "CTextureManager.h"
#include "SDL2/SDL_image.h"
#include "CGame.h"

SDL_Texture * CTextureManager::LoadTexture(const char *fileName) {

    SDL_Surface * surface = IMG_Load(fileName);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(CGame::myRenderer, surface);
    SDL_FreeSurface(surface);

    return texture;

}