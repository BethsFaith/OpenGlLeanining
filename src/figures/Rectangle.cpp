//
// Created by VerOchka on 17.08.2023.
//

#include "Rectangle.hpp"

namespace Figures {
    Rectangle::Rectangle(const std::shared_ptr<ShaderProgram>& shader_program, const std::vector<float>& coords)
        : Primitive(shader_program, 4) {
        auto ebo = std::make_shared<EBO>(std::vector<unsigned int>{{0, 1, 3, 1, 2, 3}});

        add(std::make_shared<VBO>(coords));
        add(ebo);

        vertices_attribute_numbers = 3;
    }

    void Rectangle::draw() {
        Primitive::draw();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}