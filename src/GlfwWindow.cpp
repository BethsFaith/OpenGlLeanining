//
// Created by VerOchka on 24.08.2023.
//

#include "GlfwWindow.hpp"

GlfwWindow::GlfwWindow(const int& width, const int& height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (_window == nullptr) {
        glfwTerminate();
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

GlfwWindow::~GlfwWindow() {
    delete _program;
    if (_window != nullptr) {
        glfwTerminate();
    }
}

void GlfwWindow::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* GlfwWindow::get() const {
    return _window;
}

bool GlfwWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void GlfwWindow::setClearColor(float r, float g, float b, float a) {
    _clear_color = glm::vec4{r,g,b,a};
}

void GlfwWindow::clearColor() {
    glClearColor(_clear_color.x, _clear_color.y, _clear_color.z, _clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GlfwWindow::setProgram(Program* program) {
    _program = program;
}

void GlfwWindow::run() {
    while (!shouldClose()) {
        clearColor();

        if (_program != nullptr) {
            _program->processUserInput(_window);
            _program->run();
        }

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}
