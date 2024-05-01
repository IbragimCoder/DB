cmake_minimum_required(VERSION 3.26)
project(DB)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(MAKE_PREFIX_PATH "C:\\Qt\\6.7.0\\mingw_64\\")

find_package(Qt6Widgets REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(SQLite3 REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


add_executable(DB main.cpp
        dbmanager.cpp
        dbmanager.h
        InterfaceDB.cpp
        InterfaceDB.h
        resource.qrc)
target_link_libraries(DB Qt6::Widgets Qt6::Sql)