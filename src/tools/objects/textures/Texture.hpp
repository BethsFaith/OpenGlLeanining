//
// Created by VerOchka on 22.09.2023.
//

#ifndef INC_2_SHADERS_TEXTURE_HPP
#define INC_2_SHADERS_TEXTURE_HPP

#include <iostream>

#ifndef GLFW
#include <GLFW/glfw3.h>
#include <glad/glad.h>    // подключаем glad для активации всех заголовочных файлов OpenGL
#define GLFW
#endif                    //GLFW

namespace Tools::Objects::Textures {
    class Texture {
    public:
        using Ptr = std::shared_ptr<Texture>;

        explicit Texture(std::string name, std::string path);
        ~Texture();

        void activate(unsigned int gl_int) const;
        static void deactivate();

        [[nodiscard]] unsigned int getId() const;
        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] const std::string& getPath() const;

    private:
        unsigned int _id{};
        std::string _name;
        std::string _path;
    };
}    //namespace Tools::Objects::Textures

#endif    //INC_2_SHADERS_TEXTURE_HPP
