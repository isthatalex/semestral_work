cmake_minimum_required(VERSION 3.7)
project(semestral_work)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} src)

link_libraries(SDL2)
link_libraries(SDL2_image)
add_executable(semestral_work src/main.cpp src/CGame.cpp src/CGame.h src/CTextureManager.cpp src/CTextureManager.h src/CGameObject.cpp src/CGameObject.h src/CMap.cpp src/CMap.h src/CMovingObject.cpp src/CMovingObject.h src/CHero.cpp src/CHero.h src/CEnemy.cpp src/CEnemy.h src/CInventory.cpp src/CInventory.h src/CWall.cpp src/CWall.h src/CRune.cpp src/CRune.h)




