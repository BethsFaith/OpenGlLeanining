#include <cmath>
#include <iostream>

#include "GlfwWindow.hpp"
#include "Program7.hpp"

int main() {
    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    std::cout << ProgramData::getValue<std::string>("path") << std::endl;

    GlfwWindow::init(width, height, "MyWindow");

    auto window = GlfwWindow::get();

    window->setClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    window->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    window->setProgram(new Program7);

    window->run();

    return 0;
}
