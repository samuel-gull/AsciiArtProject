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
        ascii_art_generator.h artist_base.cpp artist_base.h rectangular_grid_tiler.cpp rectangular_grid_tiler.h ascii_artist.cpp ascii_artist.h feature_extractor.cpp feature_extractor.h artist_factory.cpp artist_factory.h image_tiler_base.cpp image_tiler_base.h tiler_factory.cpp tiler_factory.h feature_extractor_base.cpp feature_extractor_base.h feature_extractor_factory.cpp feature_extractor_factory.h)

target_link_libraries( ascii_art ${OpenCV_LIBS} )


