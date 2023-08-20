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

    _texture1.bind2d("D:/CPlusPlus/Projects/OpenGL/2_shaders/src/figures/textures/src/container.jpg");
    _texture2.bind2d("D:/CPlusPlus/Projects/OpenGL/2_shaders/src/figures/textures/src/awesomeface.png");

    _shader_program->use(); // не забудьте активировать шейдер перед настройкой uniform-переменных!
    _shader_program->setInt("texture1",0);
    _shader_program->setInt("texture2", 1); // …или с помощью шейдерного класса
}

void Program2::run() {
    _texture1.bind();
    _drawer.draw();
}
