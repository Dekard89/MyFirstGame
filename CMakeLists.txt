cmake_minimum_required(VERSION 3.24)
project(Test1)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set (SFML_STATIC_LIBRARIES TRUE)

add_executable(Test1 main.cpp MovingObject.h Tank.h Projectile.cpp Projectile.h IDesrtroyed.h StaticObject.h Tanks.h)

set(SFML_DIR "C:\\Programming\\projects\\Lib\\SFML\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries (Test1 sfml-graphics)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
