//
// Created by VerOchka on 26.08.2023.
//

#include "Cube.hpp"

namespace Figures {
    Cube::Cube(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coords)
        : Cube(shader_program, std::make_shared<VBO>(coords)) {}

    Cube::Cube(const std::shared_ptr<ShaderProgram>& shader_program,
               std::shared_ptr<VBO> vbo) : Primitive(shader_program, 36) {
        auto ebo = std::make_shared<EBO>(std::vector<unsigned int>{{0, 1, 3, 1, 2, 3}});

        add(std::move(vbo));
        add(std::move(ebo));

        vertices_attribute_numbers = 3;
    }

    void Cube::draw() {
        Primitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }
}