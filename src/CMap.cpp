//
// Created by alexz on 5/4/18.
//

#include "CMap.h"
#include "CTextureManager.h"


CMap::CMap() {

    dirt = CTextureManager::LoadTexture("../images/sand.png");
    water = CTextureManager::LoadTexture("../images/water.png");
    grass = CTextureManager::LoadTexture("../images/grass.png");

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

CMap::~CMap() {
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(grass);

}

void CMap::LoadMap(int arr[20][25]) {
    for (int x_Row = 0; x_Row < 20; ++x_Row) {
        for (int x_Col = 0; x_Col < 25; ++x_Col) {
            map[x_Row][x_Col] = arr[x_Row][x_Col];
        }
    }
}

void CMap::DrawMap() {
    int type = 0;
    for (int x_Row = 0; x_Row < 20; ++x_Row) {
        for (int x_Col = 0; x_Col < 25; ++x_Col) {
            type = map[x_Row][x_Col];

            dest.x = x_Col * 32;
            dest.y = x_Row * 32;

            switch (type) {
                case 1:
                    CTextureManager::Draw(water, src, dest);
                    break;
                case 0:
                    CTextureManager::Draw(grass, src, dest);
                    break;
                case 2:
                    CTextureManager::Draw(dirt, src, dest);
                    break;
                default:
                    break;

            }

        }
    }
}

std::ostream &operator<<(std::ostream &os, const CMap &a) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 25; ++j) {
            os << a.map[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

std::string CMap::save2String() const {
    std::string str;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 25; ++j) {
            str += std::to_string(map[i][j]) + " ";
        }
        str += "\n";
    }
    return str;
}

