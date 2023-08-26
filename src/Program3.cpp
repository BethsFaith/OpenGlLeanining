//
// Created by VerOchka on 26.08.2023.
//

#include "Program3.hpp"

Program3::Program3() {
    _shader_program = std::make_shared<ShaderProgram>(ShaderSources::thirdd_vertex_shader_source, ShaderSources::texture_fragment_shader_source);

    auto rectangle = std::make_shared<Rectangle>(_shader_program, std::vector<float>{
                                                                      // координаты        // текстурные координаты
                                                                      0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // верхняя правая вершина
                                                                      0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // нижняя правая вершина
                                                                      -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // нижняя левая вершина
                                                                      -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // верхняя левая вершина
                                                                  });
    rectangle->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = true, .with_color = false});

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

    glm::mat4 model = glm::mat4(1.0f); // сначала инициализируем единичную матрицу
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

    _shader_program->set4FloatMat("model", glm::value_ptr(model));
    _shader_program->set4FloatMat("view",  glm::value_ptr(view));
    _shader_program->set4FloatMat("projection", glm::value_ptr(projection));
}

void Program3::processUserInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Program3::run() {
    _texture1.bind();
    _texture2.bind();

    _drawer.draw();
}
