//
// Created by VerOchka on 26.08.2023.
//

#include "Cube.hpp"

namespace Tools::Objects::Faces {
    Cube::Cube(const Settings &settings) : BasePrimitive(36, settings) {
        std::vector<glm::vec3> position = getPosition();
        std::vector<glm::vec3> normals = settings.with_normals ? getNormals() : std::vector<glm::vec3>();
        std::vector<glm::vec2> texture_coordinates = settings.with_texture ? getTextureCoordinates() : std::vector<glm::vec2>();

        if (settings.with_texture && settings.with_normals) {
            for (int i{}; i < 6; ++i) {
                for (int j{}; j < 6; ++j) {
                    vertices.push_back(Buffers::Vertex{
                        .position = position.at(i * 6 + j),
                        .normal = normals.at(i * 6 + j),
                        .tex_coords = texture_coordinates.at(i / 2 * 6 + j)
                    });
                }
            }
        }
        else if (settings.with_texture) {
            for (int i{}; i < 6; ++i) {
                for (int j{}; j < 6; ++j) {
                    vertices.push_back(Buffers::Vertex{
                        .position = position.at(i * 6 + j),
                        .tex_coords = texture_coordinates.at(i / 2 * 6 + j)
                    });
                }
            }
        }
        else if (settings.with_normals) {
            for (int i{}; i < 36; ++i) {
                vertices.push_back(Buffers::Vertex{
                    .position = position.at(i),
                    .normal = normals.at(i)
                });
            }
        }
        else {
            for (int i{}; i < 36; ++i) {
                vertices.push_back(Buffers::Vertex{
                    .position = position.at(i),
                });
            }
        }

        indices = std::vector<unsigned int>{{0, 1, 3, 1, 2, 3}};

        add(std::make_shared<Buffers::VBO>(vertices));
        add(std::make_shared<Buffers::EBO>(indices));
    }

    void Cube::draw() {
        BasePrimitive::draw();

        glDrawArrays(GL_TRIANGLES, 0, vertex_number);
    }

    std::vector<glm::vec3> Cube::getPosition() {
        return {
            {-0.5f, -0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f},
            {0.5f, 0.5f, -0.5f},
            {0.5f, 0.5f, -0.5f},
            {-0.5f, 0.5f, -0.5f},
            {-0.5f, -0.5f, -0.5f},

            {-0.5f, -0.5f, 0.5f},
            {0.5f, -0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, 0.5f},
            {-0.5f, -0.5f, 0.5f},

            {-0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, -0.5f},
            {-0.5f, -0.5f, -0.5f},
            {-0.5f, -0.5f, -0.5f},
            {-0.5f, -0.5f, 0.5f},
            {-0.5f, 0.5f, 0.5f},

            {0.5f, 0.5f, 0.5f},
            {0.5f, 0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f},
            {0.5f, -0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},

            {-0.5f, -0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f},
            {0.5f, -0.5f, 0.5f},
            {0.5f, -0.5f, 0.5f},
            {-0.5f, -0.5f, 0.5f},
            {-0.5f, -0.5f, -0.5f},

            {-0.5f, 0.5f, -0.5f},
            {0.5f, 0.5f, -0.5f},
            {0.5f, 0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, -0.5f}
        };
    }

    std::vector<glm::vec3> Cube::getNormals() {
        return { {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},

            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},

            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},

            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},

            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f,  0.0f},
            {0.0f, -1.0f,  0.0f},
            {0.0f, -1.0f,  0.0f},
            {0.0f, -1.0f,  0.0f},

            {0.0f,  1.0f,  0.0f},
            {0.0f,  1.0f,  0.0f},
            {0.0f,  1.0f,  0.0f},
            {0.0f,  1.0f,  0.0f},
            {0.0f,  1.0f,  0.0f},
            {0.0f,  1.0f,  0.0f},
        };
    }

    std::vector<glm::vec2> Cube::getTextureCoordinates() {
        return {
                {0.0f, 0.0f},
                {1.0f, 0.0f},
                {1.0f, 1.0f},
                {1.0f, 1.0f},
                {0.0f, 1.0f},
                {0.0f, 0.0f},

                {1.0f, 0.0f},
                {1.0f, 1.0f},
                {0.0f, 1.0f},
                {0.0f, 1.0f},
                {0.0f, 0.0f},
                { 1.0f, 0.0f},

                {0.0f, 1.0f},
                {1.0f, 1.0f},
                {1.0f, 0.0f},
                {1.0f, 0.0f},
                {0.0f, 0.0f},
                {0.0f, 1.0f},
        };
    }
}    //namespace Tools::Objects::Faces
