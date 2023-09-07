//
// Created by VerOchka on 26.08.2023.
//

#include "Cube.hpp"

namespace Figures {
    Cube::Cube(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coords)
        : Primitive(shader_program, 36) {
        auto ebo = std::make_shared<EBO>(std::vector<unsigned int>{{0, 1, 3, 1, 2, 3}});

        add(std::make_shared<VBO>(coords));
        add(ebo);

        vertices_attribute_numbers = 3;
    }

    void Cube::draw() {
        Primitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }
}