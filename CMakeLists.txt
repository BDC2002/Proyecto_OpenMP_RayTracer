cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

set(OPENCL_LIBRARY_DIR "C:/OpenCL/common/lib/x64")
link_directories(${OPENCL_LIBRARY_DIR})

set(OPENCL_INCLUDE_DIR "C:/OpenCL/common/inc") # Reemplaza con la ruta correcta de los headers (donde está CL/cl.h)
include_directories(${OPENCL_INCLUDE_DIR})

add_executable(Proyecto3 main.cpp)

target_link_libraries(Proyecto3 OpenCL)
