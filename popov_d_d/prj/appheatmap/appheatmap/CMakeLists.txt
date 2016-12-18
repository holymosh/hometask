cmake_minimum_required(VERSION 3.6)
project(appheatmap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    appheatmap.cpp
    heatmapBuilder.cpp
    heatmapBuilder.h
    heatmaptypes.h
    valuesBuilder.cpp
    valuesBuilder.h)

add_executable(appheatmap ${SOURCE_FILES})