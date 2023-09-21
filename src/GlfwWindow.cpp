//
// Created by VerOchka on 24.08.2023.
//

#include "GlfwWindow.hpp"

GlfwWindow* GlfwWindow::_instance = nullptr;

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

    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

GlfwWindow::~GlfwWindow() {
    delete _program;
    if (_window != nullptr) {
        glfwTerminate();
    }
}

void GlfwWindow::init(const int& width, const int& height, const char* title) {
    _instance = new GlfwWindow(width, height, title);
}

void GlfwWindow::run() {
    while (!shouldClose()) {
        clearColor();
        updateDeltaTime();

        if (_program != nullptr) {
            _program->processKeyboardInput(_window);
            _program->setDeltaTime(_delta_time);
            _program->run();
        }

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

void GlfwWindow::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

bool GlfwWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void GlfwWindow::clearColor() const {
    glClearColor(_clear_color.x, _clear_color.y, _clear_color.z, _clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GlfwWindow* GlfwWindow::get() {
    return _instance;
}

void GlfwWindow::setClearColor(float r, float g, float b, float a) {
    _clear_color = glm::vec4{r,g,b,a};
}

void GlfwWindow::setProgram(Program* program) {
    _program = program;

    glfwSetCursorPosCallback(_window, mouseCallback);
    glfwSetScrollCallback(_window, scrollCallback);
}

void GlfwWindow::updateDeltaTime() {
    auto currentFrame = (float)glfwGetTime();

    std::cout << std::endl << currentFrame << std::endl;

    _delta_time = currentFrame - _last_frame;
    _last_frame = currentFrame;
}

void GlfwWindow::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    _instance->_program->processMouseInput(xpos, ypos);
}

void GlfwWindow::scrollCallback(GLFWwindow* window, double x_offset, double y_offset) {
    _instance->_program->processMouseScroll(x_offset, y_offset);
}
