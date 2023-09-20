//
// Created by VerOchka on 17.08.2023.
//

#include "Rectangle.hpp"

namespace Tools::Objects::Faces {
    Rectangle::Rectangle(const Settings &settings) : Primitive(4, settings) {
        std::vector<glm::vec3> position = getPosition();
        std::vector<glm::vec2> texture_coordinates = settings.with_texture ? getTextureCoordinates() : std::vector<glm::vec2>();

        if (settings.with_texture) {
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

        indices = std::vector<unsigned int>{0, 1, 3, 1, 2, 3};

        add(std::make_shared<Buffers::VBO>(vertices));
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
}