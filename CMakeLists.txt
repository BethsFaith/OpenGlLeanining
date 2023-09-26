cmake_minimum_required(VERSION 3.25)
project(2_shaders)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/assimp EXCLUDE_FROM_ALL)

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
        src/programs/Program8.cpp
        src/constants/Shaders.cpp
        src/constants/Textures.cpp
        src/tools/shaders/ShaderProgram.cpp
        src/tools/objects/faces/Primitive.cpp
        src/tools/objects/faces/Triangle.cpp
        src/tools/objects/faces/Rectangle.cpp
        src/tools/objects/faces/buffers/RaiiBuffer.cpp
        src/tools/objects/faces/buffers/Vao.cpp
        src/tools/objects/faces/buffers/Vbo.cpp
        src/tools/objects/faces/buffers/Ebo.cpp
        src/tools/objects/faces/buffers/Vertex.cpp
        src/tools/Drawer.cpp
        src/tools/objects/textures/Texture.cpp
        src/tools/objects/textures/Loader.cpp
        src/tools/objects/libHeadears/stb_image.cpp
        src/tools/objects/faces/Cube.cpp
        src/tools/objects/Camera.cpp
        src/tools/CameraController.cpp
        src/tools/objects/Mesh.cpp
        src/tools/objects/Model.cpp
        src/constants/Models.cpp
        src/tools/objects/faces/buffers/VboT.cpp
        src/tools/lights/DirectionalLight.cpp
        src/tools/lights/SpotLight.cpp
        src/tools/lights/PointLight.cpp
        )

target_link_libraries(2_shaders ${CONAN_LIBS} assimp::assimp)
