cmake_minimum_required(VERSION 3.22.1)
project(CPP_tutorial_programming)

set(CMAKE_CXX_STANDARD 20)

# Include Eigen library
include_directories(src/main/third_party/eigen-3.4.0)

# Add VTK directories
#find_package(VTK REQUIRED PATHS "~/vtk/build" NO_DEFAULT_PATH)
#include(${VTK_USE_FILE})

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# Add the executable
add_executable(CPP_tutorial_programming
        src/main/main.cpp
        src/main/config/param.cpp
        src/main/fields/fields.cpp
        src/main/derivatives/derivative.cpp
        src/main/solver/Algorithm.cpp
        src/main/newtonImpl/newton.cpp
        src/main/streamfile/vtkWriter.cpp
)

target_link_libraries(CPP_tutorial_programming ${VTK_LIBRARIES})
