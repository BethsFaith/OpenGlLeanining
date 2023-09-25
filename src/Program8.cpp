//
// Created by VerOchka on 21.09.2023.
//

#include "Program8.hpp"

Program8::Program8() {
    configureCamera();
    configureShaders();

    using namespace Constants;

    auto model_paths = Models::getPath(Models::Sources::GUITAR_BACKPACK);

    _model = std::make_shared<Tools::Objects::Model>(model_paths.object);
}

void Program8::configureShaders() {
    using namespace Constants;

    _shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Shaders::getPath(Shaders::Sources::LOAD_MODULE_VERT),
        Shaders::getPath(Shaders::Sources::LOAD_MODULE_FRAG));

    //    _shader_program->setInt("material.diffuse", 0);
    //    _shader_program->setInt("material.specular", 1);
    //    _shader_program->setFloat("material.shininess", 32.0f);
    //
    //    // свойства света
    //    glm::vec3 white_light_color = {1.0, 1.0, 1.0};
    //    _shader_program->setInt("light.type", 0);
    //    _shader_program->set3FloatVector("light.direction",  -0.2f, -1.0f, -0.3f);
    //    _shader_program->set3FloatVector("light.ambient", white_light_color * glm::vec3(0.1f));
    //    _shader_program->set3FloatVector("light.diffuse", white_light_color * glm::vec3(0.2f));
    //    _shader_program->set3FloatVector("light.specular", white_light_color * glm::vec3(0.2f));

    // Рендеринг загруженной модели
    _shader_program->use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // смещаем вниз чтобы быть в центре сцены
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// объект слишком большой для нашей сцены, поэтому немного уменьшим его
    _shader_program->set4FloatMat("model", glm::value_ptr(model));

//    _shader_program->setCallbackUse([this](){
//        int width, height;
//        ProgramData::pullDesktopResolution(width, height);
//
//        glm::mat4 projection = glm::perspective(glm::radians(_camera->getZoom()),
//                                                (float)width / (float)height, 0.1f, 100.0f);
//        glm::mat4 view = _camera->getView();
//
//    });
}

void Program8::configureCamera() {
    _camera = std::make_shared<Tools::Objects::Camera>(glm::vec3(0.0f, 0.0f, 3.0f),
                                                       glm::vec3(0.0f, 0.0f, -1.0f),
                                                       glm::vec3(0.0f, 1.0f, 0.0f));
    _camera_controller = std::make_shared<Tools::CameraController>(_camera, 4.0f);

    int width, height;
    ProgramData::pullDesktopResolution(width, height);
    last_x = (float)width / 2;
    last_y = (float)height / 2;
}

void Program8::run() {
    _shader_program->use();
    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    glm::mat4 projection = glm::perspective(glm::radians(_camera->getZoom()),
                                            (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = _camera->getView();

    _shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    _shader_program->set4FloatMat("view", glm::value_ptr(view));

    _model->draw(_shader_program);
}

void Program8::processKeyboardInput(GLFWwindow* window) {
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

void Program8::processMouseInput(double x_pos, double y_pos) {
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

void Program8::processMouseScroll(double x_offset, double y_offset) {
    _camera_controller->zoom((float)y_offset);
}

void Program8::setDeltaTime(const float& delta_time) {
    _camera_controller->setDeltaTime(delta_time);
}
