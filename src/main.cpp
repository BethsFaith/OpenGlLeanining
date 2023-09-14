#include <cmath>
#include <iostream>

#include "GlfwWindow.hpp"
#include "Program2.hpp"

int main() {
    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    std::cout << ProgramData::getValue<std::string>("path") << std::endl;

    GlfwWindow::init(width, height, "MyWindow");

    auto window = GlfwWindow::get();

//    window->setClearColor(0.35f, 0.44f, 0.44f, 1.0f);
    window->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    window->setProgram(new Program2);

    window->run();

    return 0;
}
