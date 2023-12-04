cmake_minimum_required(VERSION 3.24)
project(PROJET_C_L2_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET_C_L2_1 main.c ListOfFloorCells.c ListOfFloorCells.h floorCell.c floorCell.h timer.c manageInts.c manageInts.h manageStrings.c Contact.c Event.c manageCommands.c manageCommands.h manageJson.c manageJson.h)
