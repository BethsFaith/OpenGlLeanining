//
// Created by VerOchka on 24.08.2023.
//

#ifndef INC_2_SHADERS_GLFWWINDOW_HPP
#define INC_2_SHADERS_GLFWWINDOW_HPP

#include <iostream>

#include "tools/objects/libHeadears/glfw.hpp"
#include "tools/objects/libHeadears/glm.hpp"
#include "Program.hpp"

class GlfwWindow {
public:
    GlfwWindow(const int& width, const int& height, const char* title);
    ~GlfwWindow();

    [[nodiscard]] GLFWwindow* get() const;

    void run();

    void setClearColor(float r, float g, float b, float a);
    void setProgram(Program* program);

protected:
    static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

    bool shouldClose();
    void clearColor() const;
private:
    void updateDeltaTime();

    float _delta_time = 0.0f;	// время между текущим и последним кадрами
    float _last_frame = 0.0f;   // время последнего кадра

    GLFWwindow* _window;
    Program* _program;

    glm::vec4 _clear_color;
};

#endif    //INC_2_SHADERS_GLFWWINDOW_HPP
