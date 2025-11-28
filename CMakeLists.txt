cmake_minimum_required(VERSION 3.18.0)
include_guard(GLOBAL)
project(tiage)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)    

set(TARGET ${PROJECT_NAME})

add_library(${TARGET} 
    STATIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Color.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Viewport.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Viewport.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/IConsole.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/IConsole.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Menu.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Menu.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Matrix.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Vec2.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/WinConsole.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/WinConsole.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/WinFileSystem.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/WinFileSystem.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/IFileSystem.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/IFileSystem.cpp"
)

target_include_directories(${TARGET}       
    PUBLIC  
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"   
)
