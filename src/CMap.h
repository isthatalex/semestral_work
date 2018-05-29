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
    friend std::ostream & operator << (std::ostream & os, const CMap & a);
    std::string save2String () const;
private:

    SDL_Rect src;
    SDL_Rect dest;

    SDL_Texture * dirt;
    SDL_Texture * water;
    SDL_Texture * grass;

    int map[20][25];

};


#endif //SEMESTRAL_WORK_CMAP_H
