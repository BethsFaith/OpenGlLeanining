//
// Created by VerOchka on 07.09.2023.
//

#include "Program4.hpp"

Program4::Program4() {
    using namespace Figures;
    _shader_program = std::make_shared<ShaderProgram>(ShaderSources::thirdd_vertex_shader_source, ShaderSources::texture_fragment_shader_source);

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
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

    int width, height;
    ProjectConstants::pullDesktopResolution(width, height);
    projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

    _camera = std::make_shared<Objects::Camera>(glm::vec3(0.0f, 0.0f,  3.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f,  0.0f));

    _shader_program->set4FloatMat("model", glm::value_ptr(model));
    _shader_program->set4FloatMat("view",  glm::value_ptr(_camera->getView()));
    _shader_program->set4FloatMat("projection", glm::value_ptr(projection));

    _camera_controller = std::make_shared<Tools::CameraController>(_camera, 4.0f);
}

void Program4::run() {
    _texture1.bind();
    _texture2.bind();

    updateView();

    glm::vec3 cubePositions[] = {glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(2.0f, 5.0f, -15.0f),
                                 glm::vec3(-1.5f, -2.2f, -2.5f),
                                 glm::vec3(-3.8f, -2.0f, -12.3f),
                                 glm::vec3(2.4f, -0.4f, -3.5f),
                                 glm::vec3(-1.7f, 3.0f, -7.5f),
                                 glm::vec3(1.3f, -2.0f, -2.5f),
                                 glm::vec3(1.5f, 2.0f, -2.5f),
                                 glm::vec3(1.5f, 0.2f, -1.5f),
                                 glm::vec3(-1.3f, 1.0f, -1.5f)};

    for (unsigned int i = 0; i < 10; i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * (i + 1);
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        _shader_program->set4FloatMat("model", glm::value_ptr(model));

        _drawer.draw();
    }
}

void Program4::processUserInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        _camera_controller->forward();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        _camera_controller->back();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        _camera_controller->left();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        _camera_controller->right();
}

void Program4::updateView() {
    _camera_controller->updateDeltaTime();

    _shader_program->set4FloatMat("view",  glm::value_ptr(_camera->getView()));
}