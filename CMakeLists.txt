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
    menu/buttons.h menu/buttons.cpp
    menu/saveform.h menu/saveform.cpp menu/saveform.ui
    menu/loadform.h menu/loadform.cpp menu/loadform.ui

    map/scenemarker.h map/scenemarker.cpp
    map/sceneviewer.h map/sceneviewer.cpp
    map/mapform.h map/mapform.cpp map/mapform.ui

    locations/location.h locations/location.cpp
    locations/locationhandler.h locations/locationhandler.cpp
    locations/location_headers.h
    locations/loc_enums.h
#Common locations
    locations/common/common_headers.h locations/common/bathenums.h
    locations/common/bathroom.h locations/common/bathroom.cpp
    locations/common/shop.h locations/common/shop.cpp
    locations/common/atm.h locations/common/atm.cpp
    locations/common/kitchenacts.h locations/common/kitchenacts.cpp
    locations/common/common.h locations/common/common.cpp
    locations/common/beach.h locations/common/beach.cpp
#Gadukino locations
    locations/gadukino/gadbana.h locations/gadukino/gadbana.cpp
    locations/gadukino/gaddvor.h locations/gadukino/gaddvor.cpp
    locations/gadukino/gadsarai.h locations/gadukino/gadsarai.cpp
    locations/gadukino/gadgarden.h locations/gadukino/gadgarden.cpp
    locations/gadukino/gadhouse.h locations/gadukino/gadhouse.cpp
    locations/gadukino/gadriver.h locations/gadukino/gadriver.cpp
    locations/gadukino/gadmarket.h locations/gadukino/gadmarket.cpp
    locations/gadukino/gadroad.h locations/gadukino/gadroad.cpp
    locations/gadukino/gadukino.h locations/gadukino/gadukino.cpp
    locations/gadukino/gadbeach.h locations/gadukino/gadbeach.cpp
    locations/gadukino/backwater.h locations/gadukino/backwater.cpp
    locations/gadukino/gadfield.h locations/gadukino/gadfield.cpp
    locations/gadukino/gadforest.h locations/gadukino/gadforest.cpp
    locations/gadukino/gadforestswamp.h locations/gadukino/gadforestswamp.cpp
    locations/gadukino/meadow.h locations/gadukino/meadow.cpp
    locations/gadukino/miroslavahome.h locations/gadukino/miroslavahome.cpp
    locations/gadukino/swamp.h locations/gadukino/swamp.cpp
    locations/gadukino/swampyard.h locations/gadukino/swampyard.cpp
    locations/gadukino/swamphouse.h locations/gadukino/swamphouse.cpp
    locations/gadukino/swampspring.h locations/gadukino/swampspring.cpp
#Pavlovo locations
#parent locations
    locations/parents/korrPar.h locations/parents/korrPar.cpp
    locations/parents/bedrpar.h locations/parents/bedrpar.cpp
#Location events
    events/event.h
    events/questenums.h
    events/eventhandler.h events/eventhandler.cpp
    events/eventenums.h events/EventHeaders.h
    events/event_enums.h
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
    events/gad_events/grandparentsevents.h events/gad_events/grandparentsevents.cpp
    events/gad_events/hanterslovesex.h events/gad_events/hanterslovesex.cpp
    events/gad_events/hanters.h events/gad_events/hanters.cpp
    events/gad_events/hantersex.h events/gad_events/hantersex.cpp
    events/gad_events/igorhanter.h events/gad_events/igorhanter.cpp
    events/gad_events/meadowevent.h events/gad_events/meadowevent.cpp
    events/gad_events/mirafather.h events/gad_events/mirafather.cpp
    events/gad_events/mirasex.h events/gad_events/mirasex.cpp
    events/gad_events/mitkabuh.h events/gad_events/mitkabuh.cpp
    events/gad_events/mitkabuhgroup.h events/gad_events/mitkabuhgroup.cpp
    events/gad_events/sergeihanter.h events/gad_events/sergeihanter.cpp
#Parent events
    events/parent_events/family.h events/parent_events/family.cpp
#Location objects
    objects/objenums.h
    objects/mirror.h objects/mirror.cpp objects/wardrobe.h objects/wardrobe.cpp
    objects/bed.h objects/bed.cpp objects/GameObj.h
    objects/objecthandler.h objects/objecthandler.cpp

    items/cloth.h items/cloth.cpp items/item.h items/item.cpp
    items/itemform.h items/itemform.cpp items/itemform.ui
    items/clothform.h items/clothform.cpp items/clothform.ui
    items/clothformTrash.ui items/clothformTrash.h items/clothformTrash.cpp
    items/card.h items/card.cpp

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
    npc/npc_enum.h
    objects/books.h objects/books.cpp
    objects/bookform.h objects/bookform.cpp objects/bookform.ui
    npc/npc_editor.h npc/npc_editor.cpp
    locations/parents/bedrpar2.h locations/parents/bedrpar2.cpp
)

target_include_directories(Game BEFORE PRIVATE ./map ./menu ./player)

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
