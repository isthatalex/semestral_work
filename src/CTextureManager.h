//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CTEXTUREMANAGER_H
#define SEMESTRAL_WORK_CTEXTUREMANAGER_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

class CTextureManager {
public:
    static SDL_Texture *LoadTexture(const char *fileName);

    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);

};

#endif //SEMESTRAL_WORK_CTEXTUREMANAGER_H
