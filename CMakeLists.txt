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
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Color.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Sprite.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Sprite.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Hitbox.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Hitbox.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Object.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Object.cpp"
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
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Renderer.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/DrawableChar.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/DrawableChar.h"
)

target_include_directories(${TARGET}       
    PUBLIC  
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"   
)
