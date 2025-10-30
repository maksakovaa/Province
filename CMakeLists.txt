cmake_minimum_required(VERSION 3.19)
project(Game LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Game
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    timeServer.h
    timeServer.cpp
    nav/scenemarker.h nav/scenemarker.cpp
    nav/sceneviewer.h nav/sceneviewer.cpp
    nav/location.h nav/location.cpp
    nav/qactionbutton.h nav/qactionbutton.cpp
    nav/mapform.h nav/mapform.cpp nav/mapform.ui
    nav/gameobj.h nav/gameobj.cpp
    nav/locationform.h nav/locationform.cpp nav/locationform.ui
    nav/objviewform.h nav/objviewform.cpp nav/objviewform.ui
    nav/bathroom.cpp

    player/player.h player/player.cpp
    player/cloth.h player/cloth.cpp
    player/wardrobe.h player/wardrobe.cpp
    player/ccsex.h player/ccsex.cpp
    player/ccalko.h player/ccalko.cpp
    player/pregnancy.h player/pregnancy.cpp
    player/enums.h
    player/item.h player/item.cpp
    player/tabwidgetplayer.h player/tabwidgetplayer.cpp player/tabwidgetplayer.ui
    player/playerDesc.cpp
    player/playerTimeSlots.cpp
    player/bagform.h player/bagform.cpp player/bagform.ui
    player/itemform.h player/itemform.cpp player/itemform.ui


    menudial.h menudial.cpp menudial.ui
    video.h video.cpp
    weather.h weather.cpp
    Functions.cpp
    Functions.h
    overlaystatus.h overlaystatus.cpp
    settings.h settings.cpp

    data/data.qrc data/locations.qrc data/clothes.qrc
    data/actions.qrc data/items.qrc data/npc.qrc

    sexviewform.h sexviewform.cpp sexviewform.ui
    selfplay.cpp
    settingsform.h settingsform.cpp settingsform.ui sex.cpp
    data/qwest.qrc
)

target_include_directories(Game BEFORE PRIVATE "." "./nav" "./player")

target_link_libraries(Game
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
        Qt::MultimediaWidgets
)
target_link_libraries(Game PRIVATE Qt6::Core)
target_link_libraries(Game PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS Game
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Game)
endif()
