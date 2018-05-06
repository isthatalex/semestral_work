//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CMAP_H
#define SEMESTRAL_WORK_CMAP_H

#include "CGame.h"

class CMap {

public:
    CMap();
    ~CMap();

    void DrawMap();
    void LoadMap(int arr[20][25]);

private:

    SDL_Rect src, dest;

    SDL_Texture * dirt;
    SDL_Texture * water;
    SDL_Texture * grass;

    int map[20][25];

};


#endif //SEMESTRAL_WORK_CMAP_H
