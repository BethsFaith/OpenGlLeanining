//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_TEXTUREWORKER_HPP
#define INC_2_SHADERS_TEXTUREWORKER_HPP

#ifndef GLFW
#include <glad/glad.h> // подключаем glad для активации всех заголовочных файлов OpenGL
#include <GLFW/glfw3.h>
#define GLFW
#endif

#include <iostream>
#include <stb_image.h>
#include <vector>

#include "Texture.hpp"

namespace Tools::Objects::Textures {
    class TextureWorker {
    public:
        struct Param {
            GLenum target;
            GLenum name;
            GLint value;
        };

        explicit TextureWorker(unsigned int id, std::string name = "");

        void addParam(Param param);

        bool bind2d(const char source[]) const;
        void bind() const;

        [[nodiscard]] const Texture& getTextureData() const;

    private:
        Texture _textureData;
        unsigned int _texture{};

        std::vector<Param> _params{};
    };
}

#endif    //INC_2_SHADERS_TEXTUREWORKER_HPP
