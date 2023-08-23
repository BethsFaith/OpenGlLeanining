//
// Created by VerOchka on 17.08.2023.
//

#include "Program2.hpp"

Program2::Program2() {
    _shader_program = std::make_shared<ShaderProgram>(ShaderSources::texture_vertex_shader_source, ShaderSources::texture_fragment_shader_source);

    auto rectangle = std::make_shared<Rectangle>(_shader_program, std::vector<float>{
                                                                      // координаты        // цвета            // текстурные координаты
                                                                      0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // верхняя правая
                                                                      0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // нижняя правая
                                                                      -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  0.0f, 0.0f,   // нижняя левая
                                                                      -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,  0.0f, 1.0f    // верхняя левая
                                                                  });
    rectangle->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = true, .with_color = true});

    _drawer.addPrimitive(rectangle);

    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST});

    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_S, .value = GL_REPEAT});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_T, .value = GL_REPEAT});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST});

    _texture1.bind2d("D:/CPlusPlus/Projects/OpenGL/2_shaders/src/figures/textures/src/container.jpg");
    _texture2.bind2d("D:/CPlusPlus/Projects/OpenGL/2_shaders/src/figures/textures/src/awesomeface.png");

    _shader_program->use();
    _shader_program->setInt("texture1",0);
    _shader_program->setInt("texture2", 1);
    _shader_program->setFloat("mix_value", _mix_value);
}

void Program2::run() {
    _texture1.bind();
    _texture2.bind();
    _drawer.draw();
}

void Program2::setMixValue(float x) {
    _shader_program->setFloat("mix_value", x);
}

void Program2::processUserInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    } else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        if (_mix_value != 1.0) {
            _mix_value += 0.1;
            setMixValue(_mix_value);
        }
    } else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        if (_mix_value != 0.0) {
            _mix_value -= 0.1;
            setMixValue(_mix_value);
        }
    }
}
