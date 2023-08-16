//
// Created by VerOchka on 16.08.2023.
//

#include "Triangle.hpp"

Triangle::Triangle(std::shared_ptr<ShaderProgram> shader_program) : Primitive(shader_program, 3){}

void Triangle::draw() {
    glBindVertexArray(VAO);

    shader_program->use();

    drawCallback();

    glDrawArrays(GL_TRIANGLES, 0, vertex_number);
}
