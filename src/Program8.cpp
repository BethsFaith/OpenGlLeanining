//
// Created by VerOchka on 21.09.2023.
//

#include "Program8.hpp"

Program8::Program8() {
    configureShaders();
    configureCamera();

    _model = std::make_shared<Tools::Objects::Model>("D:\\downloads\\survival_guitar_backpack");
    _model->setShaderProgram(_lighting_shader_program);
}

void Program8::configureShaders() {
    using namespace Constants;

    _lighting_shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_TEXT_VERT),
        Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_DIR_TEXT_FRAG));

    _lighting_shader_program->setInt("material.diffuse", 0);
    _lighting_shader_program->setInt("material.specular", 1);
    _lighting_shader_program->setFloat("material.shininess", 32.0f);

    // свойства света
    glm::vec3 white_light_color = {1.0, 1.0, 1.0};
    _lighting_shader_program->setInt("light.type", 0);
    _lighting_shader_program->set3FloatVector("light.direction",  -0.2f, -1.0f, -0.3f);
    _lighting_shader_program->set3FloatVector("light.ambient", white_light_color * glm::vec3(0.1f));
    _lighting_shader_program->set3FloatVector("light.diffuse", white_light_color * glm::vec3(0.2f));
    _lighting_shader_program->set3FloatVector("light.specular", white_light_color * glm::vec3(0.2f));
}

void Program8::configureCamera() {
    _camera = std::make_shared<Tools::Objects::Camera>(glm::vec3(0.0f, 0.0f, 3.0f),
                                                       glm::vec3(0.0f, 0.0f, -1.0f),
                                                       glm::vec3(0.0f, 1.0f, 0.0f));
    _camera_controller = std::make_shared<Tools::CameraController>(_camera, 4.0f);
}

void Program8::run() {
    _model->draw();
}

void Program8::processKeyboardInput(GLFWwindow* window) {}

void Program8::processMouseInput(double x_pos, double y_pos) {}

void Program8::processMouseScroll(double x_offset, double y_offset) {}

void Program8::setDeltaTime(const float& delta_time) {}
