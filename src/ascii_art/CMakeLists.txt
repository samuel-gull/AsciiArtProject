set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package( OpenCV REQUIRED )
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(ascii_art
        ascii_art_generator.cpp
        ascii_art_generator.h)

target_link_libraries( ascii_art ${OpenCV_LIBS} )


