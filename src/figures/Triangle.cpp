//
// Created by VerOchka on 16.08.2023.
//

#include "Triangle.hpp"

Triangle::Triangle(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coordinates)
    : Primitive(shader_program, 3){

    add(std::make_shared<VBO>(coordinates));
}

void Triangle::draw() {
    Primitive::draw();

    glDrawArrays(GL_TRIANGLES, 0, vertex_number);
}
