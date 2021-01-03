cmake_minimum_required(VERSION 3.10)
project(smolui C)

set(CMAKE_C_STANDARD 99)

include_directories("D:\\build\\SDL2-2.0.12\\include")
link_directories("D:\\build\\SDL2-2.0.12\\lib\\x64")

add_executable(smolui main.c tk/menu.c tk/menu.h tk/bitmaps.h tk/bitmap.c tk/bitmap.h tk/font.c tk/font.h tk/table.c tk/table.h tk/bitmaps.c)
target_link_libraries(smolui SDL2.lib SDL2main.lib)