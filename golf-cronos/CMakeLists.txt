cmake_minimum_required(VERSION 3.19)
project(golf-cronos LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(golf-cronos
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    recursos.qrc
    src/escenario/pantallas/iniciowindow.h src/escenario/pantallas/iniciowindow.cpp src/escenario/pantallas/iniciowindow.ui
    src/cerebro/gestorbasedatos.h src/cerebro/gestorbasedatos.cpp
)

target_link_libraries(golf-cronos
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS golf-cronos
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET golf-cronos
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

