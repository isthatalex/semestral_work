//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CTEXTUREMANAGER_H
#define SEMESTRAL_WORK_CTEXTUREMANAGER_H

#include <SDL2/SDL.h>

class CTextureManager{
public:
    static SDL_Texture* LoadTexture(const char* fileName);

};
#endif //SEMESTRAL_WORK_CTEXTUREMANAGER_H
