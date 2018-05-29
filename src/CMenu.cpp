//
// Created by alexz on 5/27/18.
//

#include <limits>
#include "CMenu.h"

int CMenu::init() {
    std::cout << "Choose your player's super power\n\t 1 for Strength -- 2 for Agility -- 3 for Speed" << std::endl;
    int j;
    std::cin >> j;

    while (!std::cin || j < 1 || j > 3) {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        system("cls");
        std::cout << "No super power for \"" << j << "\" available" << std::endl;
        std::cout << "Choose your player's super power\n\t1 for Strength -- 2 for Agility -- 3 for Speed" << std::endl;
        std::cin >> j;
    }
    return j;
}
