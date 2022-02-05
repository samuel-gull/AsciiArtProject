#include_directories(${PROJECT_SOURCE_DIR}/ascii_art)
#include_directories(${PROJECT_SOURCE_DIR}/GUI)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


add_executable(main main.cpp main_window.cpp)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/ascii_art)
target_link_libraries(main ascii_art Qt5::Core
        Qt5::Gui
        Qt5::Widgets)




