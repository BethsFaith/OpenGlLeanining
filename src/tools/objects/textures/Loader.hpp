//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_LOADER_HPP
#define INC_2_SHADERS_LOADER_HPP

#ifndef GLFW
#include <glad/glad.h> // подключаем glad для активации всех заголовочных файлов OpenGL
#include <GLFW/glfw3.h>
#define GLFW
#endif //GLFW

#include <iostream>
#include <stb_image.h>
#include <vector>

#include "Texture.hpp"

namespace Tools::Objects::Textures::Loader {
    struct Param {
        GLenum target;
        GLenum name;
        GLint value;
    };

    bool load2d(Texture& texture, const std::vector<Param>& params);
}

#endif    //INC_2_SHADERS_LOADER_HPP
