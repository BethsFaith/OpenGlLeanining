//
// Created by VerOchka on 16.09.2023.
//

#include "Program7.hpp"

glm::vec3 Program7::cube_positions[10] = {glm::vec3(0.0f, 0.0f, 0.0f),
                              glm::vec3(2.0f, 5.0f, -15.0f),
                              glm::vec3(-1.5f, -2.2f, -2.5f),
                              glm::vec3(-3.8f, -2.0f, -12.3f),
                              glm::vec3(2.4f, -0.4f, -3.5f),
                              glm::vec3(-1.7f, 3.0f, -7.5f),
                              glm::vec3(1.3f, -2.0f, -2.5f),
                              glm::vec3(1.5f, 2.0f, -2.5f),
                              glm::vec3(1.5f, 0.2f, -1.5f),
                              glm::vec3(-1.3f, 1.0f, -1.5f)};
glm::vec3 Program7::point_light_positions[4] = {glm::vec3(0.7f, 0.2f, 2.0f),
    glm::vec3(2.3f, -3.3f, -4.0f),
    glm::vec3(-4.0f, -2.0f, -12.0f),
    glm::vec3(0.0f, 0.0f, -3.0f),
};
glm::vec3 Program7::point_light_colors[4] = {
    {0.32, 0.77, 0.31},
    {0.32, 0.77, 0.31},
    {0.32, 0.77, 0.31},
    {0.32, 0.77, 0.31}
};

Program7::Program7() {
    using namespace Constants;

    _light_source_shader_program = std::make_shared<Tools::Shaders::ShaderProgram>
        (Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_TEXT_VERT),
         Shaders::getPath(Shaders::Sources::STATIC_LIGHT_FRAG));
    _lighting_shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_TEXT_VERT),
        Shaders::getPath(Shaders::Sources::COMBINED_LIGHT_FRAG));

//    auto vbo = std::make_shared<Tools::Objects::Faces::Buffers::VBO>(coords);


    Tools::Objects::Faces::Settings settings = {.with_normals = true, .with_texture = true};
    auto cube = std::make_shared<Tools::Objects::Faces::Cube>(settings);

    settings = {.with_normals = false, .with_texture = false};
    auto light_cube = std::make_shared<Tools::Objects::Faces::Cube>(settings);

    light_cube->bind(GL_STATIC_DRAW);
    cube->bind(GL_STATIC_DRAW);

    _cube_drawer.addPrimitive(cube, _lighting_shader_program);
    _light_drawer.addPrimitive(light_cube, _light_source_shader_program);

    _camera = std::make_shared<Tools::Objects::Camera>(glm::vec3(0.0f, 0.0f, 3.0f),
                                                glm::vec3(0.0f, 0.0f, -1.0f),
                                                glm::vec3(0.0f, 1.0f, 0.0f));
    _camera_controller = std::make_shared<Tools::CameraController>(_camera, 4.0f);

    _texture1.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST});
    _texture1.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST});

    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST});
    _texture2.addParam({.target = GL_TEXTURE_2D, .name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST});

    _texture1.bind2d(Textures::getPath(Textures::Sources::CONTAINER_2).c_str());
    _texture2.bind2d(Textures::getPath(Textures::Sources::CONTAINER_2_SPECULAR).c_str());

    int width, height;
    ProgramData::pullDesktopResolution(width, height);
    last_x = (float)width / 2;
    last_y = (float)height / 2;

    glm::vec3 white_light_color = {1.0, 1.0, 1.0};

    // свойства материала
    _lighting_shader_program->use();
    _lighting_shader_program->setInt("material.diffuse", 0);
    _lighting_shader_program->setInt("material.specular", 1);
    _lighting_shader_program->setFloat("material.shininess", 32.0f);

    // свойства света
    _lighting_shader_program->set3FloatVector("dirLight.direction",  -0.2f, -1.0f, -0.3f);
    _lighting_shader_program->set3FloatVector("dirLight.ambient", white_light_color * glm::vec3(1.0f));
    _lighting_shader_program->set3FloatVector("dirLight.diffuse", white_light_color * glm::vec3(1.0f));
    _lighting_shader_program->set3FloatVector("dirLight.specular", white_light_color * glm::vec3(1.0f));

    for (unsigned int i = 0; i < 4; ++i) {
        std::string elem_name = "pointLights[" + std::to_string(i) + "].";

        glm::vec3 ambient_color = point_light_colors[i] * glm::vec3(0.2f); // 0.2f
        glm::vec3 diffuse_color = point_light_colors[i] * glm::vec3(0.9f); // 0.5f
        glm::vec3 specular_color = point_light_colors[i] * glm::vec3(0.5f); // 0.5f

        _lighting_shader_program->set3FloatVector(elem_name + "ambient", ambient_color);
        _lighting_shader_program->set3FloatVector(elem_name + "diffuse", diffuse_color);
        _lighting_shader_program->set3FloatVector(elem_name + "specular", specular_color);
        _lighting_shader_program->set3FloatVector(elem_name + "position", point_light_positions[i]);

        _lighting_shader_program->setFloat(elem_name + "constant", 1.0f);
        _lighting_shader_program->setFloat(elem_name + "linear", 0.09f);
        _lighting_shader_program->setFloat(elem_name + "quadratic", 0.032f);
    }

    _lighting_shader_program->set3FloatVector("spotLight.ambient", white_light_color * glm::vec3(0.0f));
    _lighting_shader_program->set3FloatVector("spotLight.diffuse", white_light_color * glm::vec3(1.0f));
    _lighting_shader_program->set3FloatVector("spotLight.specular", glm::vec3(1.0f));
    _lighting_shader_program->setFloat("spotLight.constant", 1.0f);
    _lighting_shader_program->setFloat("spotLight.linear", 0.09f);
    _lighting_shader_program->setFloat("spotLight.quadratic", 0.032f);
    _lighting_shader_program->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    _lighting_shader_program->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(14.0f)));

    // свойства источника (точечного) света
    _light_source_shader_program->use();
    _light_source_shader_program->set3FloatVector("Color", white_light_color);
}

void Program7::run() {
    _texture1.bind();
    _texture2.bind();

    updateView();

    _lighting_shader_program->use();
    for (unsigned int i = 0; i < 10; ++i) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cube_positions[i]);
        float angle = 20.0f * float(i + 1);
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        _lighting_shader_program->set4FloatMat("model", glm::value_ptr(model));

        _cube_drawer.draw();
    }

    _light_source_shader_program->use();

    for (int i{}; i < 4; ++i) {

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, point_light_positions[i]);
        model = glm::scale(model, glm::vec3(0.2f)); // куб меньшего размера

        _light_source_shader_program->set4FloatMat("model", glm::value_ptr(model));
        _light_source_shader_program->set3FloatVector("Color", point_light_colors[i]);

        _light_drawer.draw();
    }
}

void Program7::updateView() {
    glm::vec3 light_pos(1.2f, 1.0f, 2.0f);

    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    auto projection = glm::perspective(glm::radians(_camera->getZoom()),
                                       (float)width / (float)height, 0.1f, 100.0f);

    // расположение объектов
    _lighting_shader_program->use();
    _lighting_shader_program->set4FloatMat("view", glm::value_ptr(_camera->getView()));
    _lighting_shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    _lighting_shader_program->set3FloatVector("viewPos", _camera->getPosition());

    // свойства света
    _lighting_shader_program->set3FloatVector("spotLight.position",_camera->getPosition());
    _lighting_shader_program->set3FloatVector("spotLight.direction",_camera->getFront());

    // расположение источника (точечного) света
    _light_source_shader_program->use();
    _light_source_shader_program->set4FloatMat("view", glm::value_ptr(_camera->getView()));
    _light_source_shader_program->set4FloatMat("projection", glm::value_ptr(projection));
}

void Program7::processKeyboardInput(GLFWwindow* window) {
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

void Program7::processMouseInput(double x_pos, double y_pos) {
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

    const float sensitivity = 0.04f;    // чувствительность мыши
    x_offset *= sensitivity;
    y_offset *= sensitivity;

    _camera_controller->rotate(x_offset, y_offset);
}

void Program7::processMouseScroll(double x_offset, double y_offset) {
    _camera_controller->zoom((float)y_offset);
}

void Program7::setDeltaTime(const float& delta_time) {
    _camera_controller->setDeltaTime(delta_time);
}

