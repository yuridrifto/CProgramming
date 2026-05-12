cmake_minimum_required(VERSION 3.20)
project(ClickDragProgram VERSION 1.0 LANGUAGES C)

add_executable(ClickDragProgram main.c)

target_compile_features(ClickDragProgram PRIVATE c_std_11)

target_compile_options(ClickDragProgram PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_include_directories(ClickDragProgram PRIVATE /usr/include)

target_link_libraries(ClickDragProgram PRIVATE 
    notcurses
    ncurses
)
