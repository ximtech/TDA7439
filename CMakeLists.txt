cmake_minimum_required(VERSION 3.20)
project(TDA7439 C)

set(CMAKE_C_STANDARD 99)

include(cmake/CPM.cmake)

CPMAddPackage(
        NAME STM32Core
        GITHUB_REPOSITORY ximtech/STM32Core
        GIT_TAG origin/main)

set(TDA7439_DIRECTORY
        ${I2C_POLLING_DIRECTORY}
        ${TDA7439_SOURCE_DIR}
        ${TDA7439_SOURCE_DIR}/include
        CACHE STRING "TDA7439 directories include to the main project" FORCE)

set(TDA7439_SOURCES
        ${I2C_POLLING_SOURCES}
        ${TDA7439_SOURCE_DIR}/TDA7439.c
        ${TDA7439_SOURCE_DIR}/include/TDA7439.h
        CACHE STRING "TDA7439 source files include to the main project" FORCE)