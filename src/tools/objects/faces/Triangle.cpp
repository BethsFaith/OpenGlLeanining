//
// Created by VerOchka on 16.08.2023.
//

#include "Triangle.hpp"

namespace Tools::Objects::Faces {
    Triangle::Triangle()  : Primitive(3, Settings{.with_normals = false, .with_texture_coords = false}) {
        std::vector<glm::vec3> position = {
            {0.5f,  0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f},
            {-0.5f, -0.5f, 0.0f}
        };

        add(std::make_shared<Buffers::VBO<glm::vec3>>(position));
    }

    void Triangle::draw() {
        Primitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }

    void Triangle::bindData(const unsigned int& bind_flag) {
        Primitive::bindData(bind_flag);

        Buffers::setVertexAttribute(0,
                           3,
                           (int)(sizeof(glm::vec3)),
                           (void*)nullptr);

        unbind();
    }
}
