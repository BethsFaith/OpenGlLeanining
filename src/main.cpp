#include <cmath>
#include <iostream>

#include "GlfwWindow.hpp"
#include "Program3.hpp"

int main() {
//    GlfwWindow window(2560, 1440, "MyWindow");
    GlfwWindow window(800, 600, "MyWindow");

    window.setClearColor(0.35f, 0.44f, 0.44f, 1.0f);

    window.setProgram(new Program3);

    window.run();

    return 0;
}
