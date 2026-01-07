cmake_minimum_required(VERSION 3.19)
project(Game LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Game
    WIN32 MACOSX_BUNDLE
    main.cpp
    timeServer.h timeServer.cpp

    menu/menudial.h menu/menudial.cpp menu/menudial.ui
    menu/mainwindow.cpp menu/mainwindow.h menu/mainwindow.ui
    menu/settings.h menu/settings.cpp
    menu/settingsform.h menu/settingsform.cpp menu/settingsform.ui
    menu/popup.h menu/popup.cpp
    menu/notificationqueue.h menu/notificationqueue.cpp
    menu/customshadoweffect.h menu/customshadoweffect.cpp
    menu/overlaystatus.h menu/overlaystatus.cpp
    menu/bagform.h menu/bagform.cpp menu/bagform.ui
    menu/qactbutton.h menu/qactbutton.cpp

    map/scenemarker.h map/scenemarker.cpp
    map/sceneviewer.h map/sceneviewer.cpp
    map/mapform.h map/mapform.cpp map/mapform.ui

    nav/location.h nav/location.cpp
    nav/locationhandler.h nav/locationhandler.cpp
#Common locations
    common/common_headers.h
    common/card.h common/card.cpp
    common/bathroom.h common/bathroom.cpp
    common/shop.h common/shop.cpp
    common/atm.h common/atm.cpp
    common/kitchenacts.h common/kitchenacts.cpp
    common/common.h common/common.cpp
    common/beach.h common/beach.cpp
#Gadukino locations
    gadukino/gadbana.h gadukino/gadbana.cpp
    gadukino/gaddvor.h gadukino/gaddvor.cpp
    gadukino/gadsarai.h gadukino/gadsarai.cpp
    gadukino/gadgarden.h gadukino/gadgarden.cpp
    gadukino/gadhouse.h gadukino/gadhouse.cpp
    gadukino/gadriver.h gadukino/gadriver.cpp
    gadukino/gadmarket.h gadukino/gadmarket.cpp
    gadukino/gadroad.h gadukino/gadroad.cpp
    gadukino/gadukino.h gadukino/gadukino.cpp
    gadukino/gadbeach.h gadukino/gadbeach.cpp
    gadukino/backwater.h gadukino/backwater.cpp
    gadukino/gadfield.h gadukino/gadfield.cpp
    gadukino/gadforest.h gadukino/gadforest.cpp
    gadukino/gadforestswamp.h gadukino/gadforestswamp.cpp
    gadukino/meadow.h gadukino/meadow.cpp
    gadukino/miroslavahome.h gadukino/miroslavahome.cpp
    gadukino/swamp.h gadukino/swamp.cpp
    gadukino/swampyard.h gadukino/swampyard.cpp
    gadukino/swamphouse.h gadukino/swamphouse.cpp
    gadukino/swampspring.h gadukino/swampspring.cpp
#Pavlovo locations
    pavlovo/korrPar.h pavlovo/korrPar.cpp
#Location events
    events/event.h
    events/questenums.h
    events/eventhandler.h events/eventhandler.cpp
    events/eventenums.h events/EventHeaders.h
#Gadukino events
    events/gad_events/gadukino_events.h events/gad_events/gadukino_events.cpp
    events/gad_events/gadforest_event.h events/gad_events/gadforest_event.cpp
    events/gad_events/miroslava.h events/gad_events/miroslava.cpp
    events/gad_events/mitka.h events/gad_events/mitka.cpp
    events/gad_events/riverevents.h events/gad_events/riverevents.cpp
    events/gad_events/mitkasex.h events/gad_events/mitkasex.cpp
    events/gad_events/swampevents.h events/gad_events/swampevents.cpp
    events/gad_events/bicycle.h events/gad_events/bicycle.cpp
    events/gad_events/andreihanter.h events/gad_events/andreihanter.cpp
    events/gad_events/gadforestlost.h events/gad_events/gadforestlost.cpp
    events/gad_events/gadforestrelax.h events/gad_events/gadforestrelax.cpp
    events/gad_events/pirat.h events/gad_events/pirat.cpp
    events/gad_events/grandma.h events/gad_events/grandma.cpp
    events/gad_events/grandmahelp.h events/gad_events/grandmahelp.cpp
    events/gad_events/grandpa.h events/gad_events/grandpa.cpp
    events/gad_events/grandpahelp.h events/gad_events/grandpahelp.cpp
#Parent events
    events/parent_events/family.h events/parent_events/family.cpp
#Location objects
    objects/mirror.h objects/mirror.cpp objects/wardrobe.h objects/wardrobe.cpp
    objects/bed.h objects/bed.cpp objects/GameObj.h
    objects/objecthandler.h objects/objecthandler.cpp

    items/cloth.h items/cloth.cpp items/item.h items/item.cpp
    items/itemform.h items/itemform.cpp items/itemform.ui
    items/clothform.h items/clothform.cpp items/clothform.ui
    items/clothformTrash.ui items/clothformTrash.h items/clothformTrash.cpp

    player/player.h player/player.cpp
    player/ccalko.h player/ccalko.cpp
    player/pregnancy.h player/pregnancy.cpp
    player/enums.h
    player/tabwidgetplayer.h player/tabwidgetplayer.cpp player/tabwidgetplayer.ui
    player/playerDesc.cpp
    player/drugs.h player/drugs.cpp

    sex/ccsex.h sex/ccsex.cpp
    sex/selfplay.h sex/selfplay.cpp sex/sex.h sex/sex.cpp
    sex/sexhandler.h sex/sexhandler.cpp

    video.h video.cpp
    weather.h weather.cpp
    Functions.cpp
    Functions.h

    npc/npc.h
    render.h render.cpp
    nav/location_headers.h
    nav/loc_enums.h
    events/gad_events/grandparentsevents.h events/gad_events/grandparentsevents.cpp
    events/gad_events/hanterslovesex.h events/gad_events/hanterslovesex.cpp
    events/gad_events/hanters.h events/gad_events/hanters.cpp

)

target_include_directories(Game BEFORE PRIVATE "." "./nav" "./player" "./menu" "./map")

target_link_libraries(Game
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
        Qt::MultimediaWidgets
)
target_link_libraries(Game PRIVATE Qt6::Core)
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
