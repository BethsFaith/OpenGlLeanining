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

#include <vector>
#include <stb_image.h>
#include <iostream>

class Texture {
public:
    struct Param{
        GLenum target;
        GLenum name;
        GLint value;
    };

    explicit Texture(unsigned int id);

    void addParam(Param param);

    bool bind2d(const char source[]) const;

    void bind() const;
private:
    unsigned int _texture{};
    unsigned int _id{};

    std::vector<Param> _params{};
};

#endif    //INC_2_SHADERS_TEXTURE_HPP
