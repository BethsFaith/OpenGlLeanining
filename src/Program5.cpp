//
// Created by VerOchka on 10.09.2023.
//

#include "Program5.hpp"

Program5::Program5() {
    using namespace Figures;
    using namespace Constants;

    _light_source_shader_program = std::make_shared<ShaderProgram>(Shaders::getPath(Shaders::Sources::THIRDD_UNIF_VERT),
                                                           Shaders::getPath(Shaders::Sources::STATIC_LIGHT_FRAG));
    _lighting_shader_program = std::make_shared<ShaderProgram>(Shaders::getPath(Shaders::Sources::THIRDD_UNIF_VERT),
                                                      Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_MAT_FRAG));

    std::vector<float> coords = {-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
                                 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
                                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
                                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
                                 -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
                                 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

                                 -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
                                 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
                                 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
                                 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
                                 -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
                                 -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

                                 -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
                                 -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
                                 -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
                                 -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
                                 -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
                                 -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

                                 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
                                 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
                                 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
                                 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
                                 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
                                 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

                                 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
                                 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
                                 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
                                 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
                                 -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
                                 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

                                 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
                                 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
                                 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
                                 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
                                 -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
                                 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    auto vbo = std::make_shared<VBO>(coords);

    auto cube = std::make_shared<Cube>(_lighting_shader_program, vbo);
    auto light_cube = std::make_shared<Cube>(_light_source_shader_program, vbo);

    light_cube->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = false, .with_color = false, .offset = 3});
    cube->bind(Settings{.bind_flag = GL_STATIC_DRAW, .with_texture = false, .with_color = false, .with_normal_vectors = true});

    _drawer.addPrimitive(light_cube);
    _drawer.addPrimitive(cube);

    _camera = std::make_shared<Objects::Camera>(glm::vec3(0.0f, 0.0f, 3.0f),
                                                glm::vec3(0.0f, 0.0f, -1.0f),
                                                glm::vec3(0.0f, 1.0f, 0.0f));
    _camera_controller = std::make_shared<Tools::CameraController>(_camera, 4.0f);

    _lighting_shader_program->use();

//    _lighting_shader_program->set3FloatVector("material.ambient", 0.1f, 0.1f, 0.1f);
//    _lighting_shader_program->set3FloatVector("material.diffuse", 1.0f, 0.5f, 0.31f);
//    _lighting_shader_program->set3FloatVector("material.specular", 0.5f, 0.5f, 0.5f);
    _lighting_shader_program->set3FloatVector("material.ambient", 0.05375f, 0.05f, 0.06625f);
    _lighting_shader_program->set3FloatVector("material.diffuse", 0.18725f, 0.17f, 0.22525f);
    _lighting_shader_program->set3FloatVector("material.specular", 0.332741f, 0.328634f, 0.346435f);
    _lighting_shader_program->setFloat("material.shininess", 32.0f);

    glm::vec3 light_color = {1.0, 1.0, 1.0};

    _light_source_shader_program->use();
    _light_source_shader_program->set3FloatVector("Color",  light_color);

    int width, height;
    ProgramData::pullDesktopResolution(width, height);
    last_x = (float)width / 2;
    last_y = (float)height / 2;
}

void Program5::run() {
    updateView();
    _drawer.draw();
}

void Program5::processKeyboardInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        _camera_controller->forward();
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        _camera_controller->back();
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        _camera_controller->left();
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        _camera_controller->right();
    }
}

void Program5::processMouseInput(double x_pos, double y_pos) {
    if (first_mouse)    // изначально установлено значение true
    {
        last_x = x_pos;
        last_y = y_pos;

        first_mouse = false;

        return;
    }

    float x_offset = x_pos - last_x;
    float y_offset =
        last_y
        - y_pos;    // уменьшаемое и вычитаемое поменяны местами, так как диапазон y-координаты определяется снизу вверх

    last_x = x_pos;
    last_y = y_pos;

    const float sensitivity = 0.05f;    // чувствительность мыши
    x_offset *= sensitivity;
    y_offset *= sensitivity;

    _camera_controller->rotate(x_offset, y_offset);
}

void Program5::processMouseScroll(double x_offset, double y_offset) {
    _camera_controller->zoom((float)y_offset);
}

void Program5::setDeltaTime(const float& delta_time) {
    _camera_controller->setDeltaTime(delta_time);
}

void Program5::updateView() {
    glm::vec3 light_pos(1.2f, 1.0f, 2.0f);
    float moveAmount = glm::sin((float)glfwGetTime());
    light_pos.x += moveAmount;

    glm::mat4 model = glm::mat4(1.0f);    // сначала инициализируем единичную матрицу

    int width, height;
    ProgramData::pullDesktopResolution(width, height);
    auto projection = glm::perspective(glm::radians(_camera->getZoom()), (float)width / (float)height, 0.1f, 100.0f);

    _lighting_shader_program->use();
    _lighting_shader_program->set4FloatMat("model", glm::value_ptr(model));
    _lighting_shader_program->set4FloatMat("view", glm::value_ptr(_camera->getView()));
    _lighting_shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    _lighting_shader_program->set3FloatVector("light.position", light_pos);
    _lighting_shader_program->set3FloatVector("viewPos", _camera->getPosition());

    glm::vec3 light_color = {1.0, 1.0, 1.0};
//    light_color.x = sin(glfwGetTime() * 2.0f);
//    light_color.y = sin(glfwGetTime() * 0.7f);
//    light_color.z = sin(glfwGetTime() * 1.3f);

    glm::vec3 ambient_color = light_color * glm::vec3(1.0f); // 0.2f
    glm::vec3 diffuse_color = light_color * glm::vec3(1.0f); // 0.5f

    _lighting_shader_program->set3FloatVector("light.ambient", ambient_color);
    _lighting_shader_program->set3FloatVector("light.diffuse", diffuse_color);
    _lighting_shader_program->set3FloatVector("light.specular", glm::vec3(1.0f));

    _light_source_shader_program->use();
    _light_source_shader_program->set4FloatMat("view", glm::value_ptr(_camera->getView()));
    _light_source_shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    _light_source_shader_program->set3FloatVector("Color",  light_color);

    model = glm::translate(model, light_pos);
    model = glm::scale(model, glm::vec3(0.2f)); // куб меньшего размера

    _light_source_shader_program->set4FloatMat("model", glm::value_ptr(model));
}
