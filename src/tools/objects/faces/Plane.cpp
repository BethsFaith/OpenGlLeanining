//
// Created by VerOchka on 29.09.2023.
//

#include "Plane.hpp"

namespace Tools::Objects::Faces {
    Plane::Plane(const Settings& settings) : Primitive(6, settings) {
        std::vector<glm::vec3> position = {
            {5.0f, -0.5f,  5.0f},
            {-5.0f, -0.5f,  5.0f},
            {-5.0f, -0.5f, -5.0f},
            {5.0f, -0.5f,  5.0f},
            {-5.0f, -0.5f, -5.0f},
            {5.0f, -0.5f, -5.0f}
        };
        std::vector<glm::vec2> texture_coordinates =  {
            {2.0f, 0.0f},
            {0.0f, 0.0f},
            {0.0f, 2.0f},
            {2.0f, 0.0f},
            {0.0f, 2.0f},
            {2.0f, 2.0f}
        };

        std::vector<Buffers::Vertex> vertices;

        if (settings.with_texture_coords) {
            for (int i{}; i < vertex_number; ++i) {
                vertices.push_back({
                    .position = position.at(i),
                    .tex_coords = texture_coordinates.at(i)
                });
            }
        }
        else {
            for (int i{}; i < vertex_number; ++i) {
                vertices.push_back({
                    .position = position.at(i)
                });
            }
        }

        add(std::make_shared<Buffers::VBO<Buffers::Vertex>>(vertices));
    }

    void Plane::bindData(const unsigned int& bind_flag) {
        Primitive::bindData(bind_flag);

        int index = 0;

        Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)),
                                    (void*)offsetof(Buffers::Vertex, position));
        if (settings.with_texture_coords) {
            Buffers::setVertexAttribute(index++, 2, (int)(sizeof(Buffers::Vertex)),
                                        (void*)offsetof(Buffers::Vertex, tex_coords));
        }

        unbind();
    }

    void Plane::draw() {
        Primitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }
}