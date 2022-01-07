cmake_minimum_required(VERSION 3.21)
project(AsciiArtProject)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(${PROJECT_SOURCE_DIR}/ascii_art)
add_subdirectory(${PROJECT_SOURCE_DIR}/GUI)






