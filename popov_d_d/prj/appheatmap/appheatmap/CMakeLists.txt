cmake_minimum_required(VERSION 3.6)
project(appheatmap)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES appheatmap.cpp heatmapBuilder.cpp heatmapBuilder.h valuesBuilder.cpp valuesBuilder.h)

set(OpenCV_DIR "C:\\opencv\\opencv\\build")
FIND_PACKAGE(OpenCV REQUIRED)
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
INCLUDE_DIRECTORIES( ${OPENCV_INCLUDE_DIR} )

add_executable(appheatmap ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(appheatmap ${OpenCV_LIBS})

