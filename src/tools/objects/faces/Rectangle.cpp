//
// Created by VerOchka on 17.08.2023.
//

#include "Rectangle.hpp"

namespace Tools::Objects::Faces {
    Rectangle::Rectangle(const Settings &settings) : Primitive(4, settings) {
        std::vector<glm::vec3> position = getPosition();
        std::vector<glm::vec2> texture_coordinates = settings.with_texture_coords ? getTextureCoordinates() : std::vector<glm::vec2>();

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

        auto indices = std::vector<unsigned int>{0, 1, 3, 1, 2, 3};

        add(std::make_shared<Buffers::VBO<Buffers::Vertex>>(vertices));
        add(std::make_shared<Buffers::EBO>(indices));
    }

    void Rectangle::draw() {
        Primitive::draw();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    std::vector<glm::vec3> Rectangle::getPosition() {
        return {
            {0.5f,  0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f},
            {-0.5f, -0.5f, 0.0f},
            {  -0.5f,  0.5f, 0.0f}
        };
    }

    std::vector<glm::vec2> Rectangle::getTextureCoordinates() {
        return {
            {1.0f, 0.0f},
            {0.0f, 0.0f},
            {0.0f, 1.0f}
        };
    }

    std::vector<glm::vec3> Rectangle::getNormals() {
        return {};
    }

    void Rectangle::bindData(const unsigned int& bind_flag) {
        Primitive::bindData(bind_flag);

        int index = 0;

        Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, position));
        if (settings.with_normals) {
            Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, normal));
        }
        if (settings.with_texture_coords) {
            Buffers::setVertexAttribute(index++, 2, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, tex_coords));
        }
        if (settings.with_tangent) {
            Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, tangent));
        }
        if (settings.with_bitangent) {
            Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, bitangent));
        }

        unbind();
    }
}