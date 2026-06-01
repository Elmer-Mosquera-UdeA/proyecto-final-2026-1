cmake_minimum_required(VERSION 3.19)
project(golf-cronos LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql Multimedia)

set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(golf-cronos
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/recursos.qrc
    src/cerebro/gestorbasedatos.h src/cerebro/gestorbasedatos.cpp
    src/escenario/pantallas/iniciowindow.h src/escenario/pantallas/iniciowindow.cpp src/escenario/pantallas/iniciowindow.ui
    src/escenario/widgets/loginwidget.h src/escenario/widgets/loginwidget.cpp src/escenario/widgets/loginwidget.ui
    src/escenario/widgets/registrarsewidget.h src/escenario/widgets/registrarsewidget.cpp src/escenario/widgets/registrarsewidget.ui
    src/escenario/widgets/modosgamewidget.h src/escenario/widgets/modosgamewidget.cpp src/escenario/widgets/modosgamewidget.ui
    src/escenario/widgets/portadawidget.h src/escenario/widgets/portadawidget.cpp src/escenario/widgets/portadawidget.ui
    src/escenario/widgets/juegomodunowidget.h src/escenario/widgets/juegomodunowidget.cpp src/escenario/widgets/juegomodunowidget.ui
)

target_link_libraries(golf-cronos
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
        Qt6::Multimedia
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

