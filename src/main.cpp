#include <cmath>
#include <iostream>

#include "GlfwWindow.hpp"
#include "Program1.hpp"
#include "Program2.hpp"

int main() {
    GlfwWindow window(2560, 1440, "MyWindow");
    window.setClearColor(0.35f, 0.44f, 0.44f, 1.0f);

    window.setProgram(new Program2);

    window.run();

    return 0;
}
