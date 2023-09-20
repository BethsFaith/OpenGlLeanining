//
// Created by VerOchka on 16.08.2023.
//

#include "Triangle.hpp"

namespace Tools::Objects::Faces {
    Triangle::Triangle()  : Primitive(3, Settings{.with_normals = false, .with_texture = false}) {
        std::vector<glm::vec3> position = {
            {0.5f,  0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f},
            {-0.5f, -0.5f, 0.0f}
        };

        for (int i{}; i < vertex_number; ++i) {
            vertices.push_back({.position = position.at(i)});
        }

        add(std::make_shared<Buffers::VBO>(vertices));
    }

    void Triangle::draw() {
        Primitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }
}
