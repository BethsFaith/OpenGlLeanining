//
// Created by VerOchka on 24.08.2023.
//

#ifndef INC_2_SHADERS_GLFWWINDOW_HPP
#define INC_2_SHADERS_GLFWWINDOW_HPP

#include <iostream>

#include "programs/Program.hpp"
#include "tools/objects/libHeadears/glfw.hpp"
#include "tools/objects/libHeadears/glm.hpp"

class GlfwWindow {
public:
    static void init(const int& width, const int& height, const char* title);

    [[nodiscard]] static GlfwWindow* get() ;

    void run();

    void setClearColor(float r, float g, float b, float a);
    void setProgram(Program* program);

protected:
    static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void scrollCallback(GLFWwindow* window, double x_offset, double y_offset);

    bool shouldClose();
    void clearColor() const;
private:
    GlfwWindow(const int& width, const int& height, const char* title);
    ~GlfwWindow();

    void updateDeltaTime();

    float _delta_time = 0.0f;	// время между текущим и последним кадрами
    float _last_frame = 0.0f;   // время последнего кадра

    static GlfwWindow* _instance;

    GLFWwindow* _window = nullptr;
    Program* _program = nullptr;

    glm::vec4 _clear_color{};
};

#endif    //INC_2_SHADERS_GLFWWINDOW_HPP
