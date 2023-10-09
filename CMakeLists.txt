make_ minimum_ required (VERSION 3.7.2) set(PRJ_ NAME songlist)
project(S(PRJ. NAME) VERSION 1.0.0 LANGUAGES CXX
set(CMAKE CXX_STANDARD 11)
set(CMAKE_CXX_ STANDARD_REQUIRED ON)
set(CMAKE AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ LIBRARY_OUTPUT_ DIRECTORY ${CMAKE_ BINARY_DIR}/Ib)
set (CMAKE_RUNTIME_OUTPUT _DIRECTORY ${CMAKE, BINARY DIRY}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Q15 COMPONENTS Core REQUIRED) find_package(Q15 COMPONENTS Widgets REQUIRED)
find_package(Q15 COMPONENTS Gui REQUIRED) find_package(Qt5 COMPONENTS Sq| REQUIREO)
find_package(Qt5 COMPONENTS Xml REQUIRED)
# Формирование списка заголовочных файлов file(GLOB_RECURSE SRC_H src/*.h)
# Формирование списка заголовочных файлов
file(GLOB_RECURSE SRC_H src/*.h)
qt5_wrap_cpp(MOC_SRC_H ${SRC_H})
# Формирование списка файлов с исходным кодом
file(GLOB_RECURSE SRC_C src/* .cpp) file(GLOB_RECURSE SRC_UI src/*.ul)
gt5_wrap_ui(SRC_UI1 ${SRC_UI}) file(GLOB_RECURSE SRC_RCC src/*.qrc)
qt5_add_resources(SRC_RES ${RCC _RCC})
add_executable(${PRJ_NAME} ${SRC_C) ${SRC_H} ${SRC_UI1} ${SRC_RES) ${MOC_SRC_H} )
target_link_libraries( ${PRJ_NAME}
QtS::Core
Qt5:Widgets
QtS::Gui
Q15:Sal
QtS::Xml )
include(GenerateSourceGroups.cmake) GroupSources(src)
set_property(TARGET ${PRJ_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY
"${CMAKE_BINARY_DIR}/bin")
set_property(TARGET ${PRJ_NAME} PROPERTY VS_DEBUGGER_ENVIRONMENT
"PATH=%PATH%;${CMAKE_PREFIX_PATH}")
set property(DIRECTORY ${MAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_ PROJECT ${PRJ _NAME})