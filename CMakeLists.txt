cmake_minimum_required(VERSION 3.7)
project(semestral_work)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${semestral_work_SOURCE_DIR}/cmake")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(PNG REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
add_executable(semestral_work main.cpp CGame.cpp CGame.h CTextureManager.h CTextureManager.cpp CGameObject.cpp CGameObject.h CMap.cpp CMap.h)
target_link_libraries(semestral_work ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})



