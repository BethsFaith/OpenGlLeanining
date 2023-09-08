//
// Created by VerOchka on 26.08.2023.
//

#include "Program3.hpp"

Program3::Program3() {
    using namespace Figures;
    _shader_program = std::make_shared<ShaderProgram>(ShaderSources::thirdd_vertex_shader_source, ShaderSources::texture_fragment_shader_source);

//    auto rectangle = std::make_shared<Rectangle>(_shader_program, std::vector<float>{
//                                                                      // координаты        // текстурные координаты
//                                                                      0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // верхняя правая вершина
//                                                                      0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // нижняя правая вершина
//                                                                      -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // нижняя левая вершина
//                                                                      -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // верхняя левая вершина
//                                                                  });
//    rectangle->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = true, .with_color = false});

    auto cube = std::make_shared<Cube>(_shader_program, std::vector<float>{// координаты        // текстурные координаты
                                                                           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
                                                                           0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
                                                                           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                                                                           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                                                                           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                                                                           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

                                                                           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                                                                           0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                                                                           0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                                                                           0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                                                                           -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
                                                                           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

                                                                           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                                                                           -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                                                                           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                                                                           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                                                                           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                                                                           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                                                                           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                                                                           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                                                                           0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                                                                           0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                                                                           0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                                                                           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                                                                           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                                                                           0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
                                                                           0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                                                                           0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                                                                           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                                                                           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

                                                                           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                                                                           0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                                                                           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                                                                           0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                                                                           -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                                                                           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
                                                        });
    cube->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = true, .with_color = false});
    _drawer.addPrimitive(cube);

    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name =GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST});

    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_S, .value = GL_REPEAT});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_T, .value = GL_REPEAT});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST});

    _texture1.bind2d(TextureSources::container_path.c_str());
    _texture2.bind2d(TextureSources::face_path.c_str());

    _shader_program->use();
    _shader_program->setInt("texture1",0);
    _shader_program->setInt("texture2", 1);

    glm::mat4 model = glm::mat4(1.0f); // сначала инициализируем единичную матрицу
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

//    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)700 / (float)height, 0.1f, 100.0f);

    _shader_program->set4FloatMat("model", glm::value_ptr(model));
    _shader_program->set4FloatMat("view",  glm::value_ptr(view));
    _shader_program->set4FloatMat("projection", glm::value_ptr(projection));
}

void Program3::processKeyboardInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Program3::run() {
    _texture1.bind();
    _texture2.bind();

    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    for(unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * (i+1);
        if (i % 3 == 0) {
            model = glm::rotate(model, glm::radians(angle * (float)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
        } else {
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        }
        _shader_program->set4FloatMat("model", glm::value_ptr(model));

        _drawer.draw();
    }
//    glm::mat4 model = glm::mat4(1.0f);
//    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//    _shader_program->set4FloatMat("model", glm::value_ptr(model));
//
//    _drawer.draw();
}
