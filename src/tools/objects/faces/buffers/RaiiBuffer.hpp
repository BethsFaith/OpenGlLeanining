//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_RAIIBUFFER_HPP
#define INC_2_SHADERS_RAIIBUFFER_HPP

#ifndef GLFW
#include <glad/glad.h> // подключаем glad для активации всех заголовочных файлов OpenGL
#include <GLFW/glfw3.h>
#define GLFW
#endif

namespace Tools::Objects::Faces::Buffers {
    class RaiiBuffer {
    public:
        explicit RaiiBuffer(const int& priority);
        virtual ~RaiiBuffer() = default;

        virtual void bind(const unsigned int& bind_flag) = 0;

        virtual void unbind() = 0;

        [[nodiscard]] unsigned int getPriority() const;

        [[nodiscard]] virtual unsigned int get() const = 0;

    private:
        unsigned int _priority;
    };
}

#endif    //INC_2_SHADERS_RAIIBUFFER_HPP
