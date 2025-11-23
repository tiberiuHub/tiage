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
<<<<<<< HEAD
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Viewport.h"
=======
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/IConsole.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/IConsole.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Menu.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Menu.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Matrix.h"
<<<<<<< HEAD
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Vec2.h"
=======
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/Position.h"
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/tiage/WinConsole.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/WinConsole.cpp"
)

target_include_directories(${TARGET}       
    PUBLIC  
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"   
)
