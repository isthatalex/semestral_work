//
// Created by alexz on 5/4/18.
//

#ifndef SEMESTRAL_WORK_CGAME_H
#define SEMESTRAL_WORK_CGAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
class CGame {
public:
    CGame();
    ~CGame();

    void init (const char* title, int xpos, int ypos,
                int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running (); // is the game running

    static SDL_Renderer * myRenderer;

    bool checkCollision(const SDL_Rect & a, const SDL_Rect & b);

private:
    bool isRunning;
    SDL_Window * myWindow;


};


#endif //SEMESTRAL_WORK_CGAME_H
