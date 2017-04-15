cmake_minimum_required(VERSION 3.0)
project(mpl_embed)

# Set the standard for C++ to c++11
set(CMAKE_CXX_STANDARD 11)

# Find python!
# ---
# Add the find python script from pybind11
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/externals/pybind11/tools/")
set(Python_ADDITIONAL_VERSIONS 3.7 3.6 3.5 3.4)
find_package(PythonLibsNew ${PYBIND11_PYTHON_VERSION} REQUIRED)
MESSAGE(STATUS "PYTHON_LIBRARIES: ${PYTHON_LIBRARIES}")
MESSAGE(STATUS "PYTHON_INCLUDE_DIRS: ${PYTHON_INCLUDE_DIRS}")

# Build the executable and link to Eigen and pybind11
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories("externals/Eigen/")
include_directories("externals/pybind11/include")
add_executable(mpl_embed main.cpp)
target_link_libraries(mpl_embed ${PYTHON_LIBRARIES})