//
// Created by VerOchka on 29.09.2023.
//

#include "Program.hpp"

Program::Program() {
    camera = std::make_shared<Tools::Objects::Camera>(glm::vec3(0.0f, 0.0f, 3.0f),
                                                       glm::vec3(0.0f, 0.0f, -1.0f),
                                                       glm::vec3(0.0f, 1.0f, 0.0f));
    camera_controller = std::make_shared<Tools::CameraController>(camera, 4.0f);

    int width, height;
    ProgramData::pullDesktopResolution(width, height);
    last_x = (float)width / 2;
    last_y = (float)height / 2;
}

void Program::processKeyboardInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera_controller->forward();
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera_controller->back();
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera_controller->left();
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera_controller->right();
    }
}

void Program::processMouseInput(double x_pos, double y_pos) {
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

    camera_controller->rotate(x_offset, y_offset);
}

void Program::processMouseScroll(double x_offset, double y_offset) {
    camera_controller->zoom((float)y_offset);
}

void Program::setDeltaTime(const float& delta_time) {
    camera_controller->setDeltaTime(delta_time);
}