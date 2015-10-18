#////////////////////////////////////////////////////////////////////////////
#//
#//  This file is part of Artificial Horizon
#//


########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8.9)
project(ArtificialHorizon)
add_executable(Graph Graph.cpp)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(Graph ${SDL2_LIBRARIES})
