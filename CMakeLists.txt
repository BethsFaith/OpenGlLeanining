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
        src/figures/shaders/ShaderProgram.cpp
        src/figures/Primitive.cpp
        src/figures/Triangle.cpp
        src/figures/Rectangle.cpp
        src/figures/buffers/RaiiBuffer.cpp
        src/figures/buffers/Vao.cpp
        src/figures/buffers/Vbo.cpp
        src/figures/buffers/Ebo.cpp
        src/figures/Drawer.cpp
        src/Program1.cpp
        src/Program2.cpp
        src/figures/textures/Texture.cpp
        src/lib_headears/stb_image.cpp
        src/lib_headears/glm.hpp
        src/GlfwWindow.cpp src/Program3.cpp src/Program3.hpp src/figures/Cube.cpp src/figures/Cube.hpp)

target_link_libraries(2_shaders ${CONAN_LIBS})
