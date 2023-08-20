//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_TEXTURE_HPP
#define INC_2_SHADERS_TEXTURE_HPP

#ifndef GLFW
#include <glad/glad.h> // подключаем glad для активации всех заголовочных файлов OpenGL
#include <GLFW/glfw3.h>
#define GLFW
#endif

#include <stb_image.h>
#include <iostream>

class Texture {
public:
    explicit Texture(unsigned int id);

    bool bind2d(const char source[]) const;

    void bind() const;
private:
    unsigned int _texture{};
    unsigned int _id{};
};

#endif    //INC_2_SHADERS_TEXTURE_HPP
