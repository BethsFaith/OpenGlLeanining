cmake_minimum_required(VERSION 3.25)
project(2_shaders)

set(CMAKE_CXX_STANDARD 20)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}
        BASIC_SETUP
        BUILD missing)

add_executable(2_shaders
        src/main.cpp
        src/main.cpp src/figures/shaders/ShaderProgram.cpp src/figures/shaders/ShaderProgram.hpp src/figures/Triangles.cpp src/figures/Triangles.hpp src/figures/Triangles.hpp src/figures/Primitive.cpp src/figures/Primitive.hpp src/figures/Primitive.hpp src/figures/Triangle.cpp src/figures/Triangle.hpp src/figures/Triangle.hpp src/figures/Drawer.cpp src/figures/Drawer.hpp src/Program1.cpp src/Program1.hpp src/Program1.hpp src/figures/Settings.hpp src/figures/Settings.hpp)

target_link_libraries(2_shaders ${CONAN_LIBS})
