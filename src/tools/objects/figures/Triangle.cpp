//
// Created by VerOchka on 16.08.2023.
//

#include "Triangle.hpp"

namespace Figures {
    Triangle::Triangle(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coordinates)
        : Triangle(shader_program, std::make_shared<VBO>(coordinates)) {}

    Triangle::Triangle(const std::shared_ptr<ShaderProgram>& shader_program, std::shared_ptr<VBO> vbo)  : Primitive(shader_program, 3) {
        add(std::move(vbo));
    }

    void Triangle::draw() {
        Primitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }
}
