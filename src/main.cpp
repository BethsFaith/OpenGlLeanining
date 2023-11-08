#include <cmath>
#include <iostream>

#include "GlfwWindow.hpp"
#include "programs/Program8.hpp"
#include <stb_image.h>

int main() {
    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    std::cout << ProgramData::getValue<std::string>("path") << std::endl;

    GlfwWindow::init(width, height, "OpenGL!!!");

    stbi_set_flip_vertically_on_load(true);

    auto window = GlfwWindow::get();

//    window->setClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    window->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    window->setClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    window->setProgram(new Program8);

    window->run();

    return 0;
}
