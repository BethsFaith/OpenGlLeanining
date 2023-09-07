#include <cmath>
#include <iostream>

#include "GlfwWindow.hpp"
#include "Program3.hpp"

int main() {
    int width, height;
    ProjectConstants::pullDesktopResolution(width, height);

    std::cout << ProjectConstants::getProjectValue<std::string>("path") << std::endl;

    GlfwWindow window(width, height, "MyWindow");

    window.setClearColor(0.35f, 0.44f, 0.44f, 1.0f);

    window.setProgram(new Program3);

    window.run();

    return 0;
}
