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
        src/GlfwWindow.cpp
        src/Program1.cpp
        src/Program2.cpp
        src/Program3.cpp
        src/Program3.hpp
        src/Program4.cpp
        src/tools/objects/figures/shaders/ShaderProgram.cpp
        src/tools/objects/figures/Primitive.cpp
        src/tools/objects/figures/Triangle.cpp
        src/tools/objects/figures/Rectangle.cpp
        src/tools/objects/figures/buffers/RaiiBuffer.cpp
        src/tools/objects/figures/buffers/Vao.cpp
        src/tools/objects/figures/buffers/Vbo.cpp
        src/tools/objects/figures/buffers/Ebo.cpp
        src/tools/objects/figures/Drawer.cpp
        src/tools/objects/figures/textures/Texture.cpp
        src/tools/objects/libHeadears/stb_image.cpp
        src/tools/objects/figures/Cube.cpp
        src/tools/objects/Camera.cpp
        src/tools/CameraController.cpp
        )

target_link_libraries(2_shaders ${CONAN_LIBS})
