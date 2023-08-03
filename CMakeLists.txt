cmake_minimum_required(VERSION 3.5)

project(boostTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CONFIG_PATH_Qt5_Window_64        D:/Apply/QT/5.15.2/msvc2019_64/                          )
set(QtExample_Qt_Path ${CONFIG_PATH_Qt5_Window_64})
list(APPEND CMAKE_PREFIX_PATH ${QtExample_Qt_Path})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
set(CONFIG_PATH_vcpkg  D:/Apply/VCPKG/vcpkg/scripts/buildsystems/vcpkg.cmake )
set(PROJECT_SOURCES

        OutOfCore/BasicType.h
        OutOfCore/BlockwiseImage.h
        OutOfCore/DiskBigImage.h
        OutOfCore/DiskBigImageInterface.h
        OutOfCore/GiantImageInterface.h
        OutOfCore/HierarchicalImage.h
        OutOfCore/ImageInterface.h
        OutOfCore/IndexMethodInterface.h
        OutOfCore/MainPage.h
        OutOfCore/UtlityFunc.h
        OutOfCore/BlockwiseImage.hpp
        OutOfCore/DiskBigImage.hpp
        OutOfCore/HierarchicalImage.hpp
        OutOfCore/IndexMethod.hpp
        OutOfCore/Lru.hpp

        main.cpp
        mainwindow.cpp
        mainwindow.h
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(boostTest
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET boostTest APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(boostTest SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(boostTest
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(boostTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(boostTest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS boostTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(boostTest)
endif()

message(STATUS "设置工具链文件为${CONFIG_PATH_vcpkg}")
set(CMAKE_TOOLCHAIN_FILE ${CONFIG_PATH_vcpkg})

find_package(Boost COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "boost include path is : ${Boost_INCLUDE_DIRS}")
    message(STATUS "boost library path is : ${Boost_LIBRARY_DIRS}")
    message(STATUS "boost libraries is : ${Boost_LIBRARIES}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(WARNING "boost not found.")
endif()


#链接路径
set(OpencvDir D:/testVcpgk/vcpkg/packages/opencv4_x64-windows/share/opencv)
list(APPEND CMAKE_PREFIX_PATH ${OpencvDir})

set(StxxlDir D:/testVcpgk/vcpkg/packages/stxxl_x64-windows/share/stxxl)
list(APPEND CMAKE_PREFIX_PATH ${StxxlDir})
#库的设置
############################# OpenCV #############################
find_package(OpenCV REQUIRED)

target_link_libraries(boostTest PRIVATE ${OpenCV_LIBS})
############################# StxxlDir #############################
find_package(stxxl CONFIG REQUIRED)
target_link_libraries(boostTest PRIVATE stxxl)
