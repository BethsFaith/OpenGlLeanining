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
private:
    static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

    bool shouldClose();
    void clearColor();

    GLFWwindow* _window;
    Program* _program;

    glm::vec4 _clear_color;
};

#endif    //INC_2_SHADERS_GLFWWINDOW_HPP
