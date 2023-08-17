//
// Created by VerOchka on 16.08.2023.
//

#include "Primitive.hpp"

Primitive::Primitive(std::shared_ptr<ShaderProgram> shader_program, const int& vertex_number_)
    : shader_program(shader_program),
      vertex_number(vertex_number_) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    drawCallback = []() {};
}

void Primitive::setDrawCallback(std::function<void()> function) {
    drawCallback = std::move(function);
}

void Primitive::bindVerticesToCoordinates(std::vector<float> coordinates, const Settings& settings) {
    int coordinates_number = vertex_number * 3;

    if (settings.with_color) {
        coordinates_number += vertex_number * 3;
    }
    if (settings.with_texture) {
        coordinates_number += vertex_number * settings.dimension;
    }

    if (coordinates.size() != coordinates_number) {
        throw std::exception(
            std::format("Wrong number of coordinates: {} when need {}\n", coordinates.size(), coordinates_number)
                .c_str());
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, coordinates_number * sizeof(float), coordinates.data(), settings.bind_flag);

    if (!settings.with_color && !settings.with_texture) {
        setVertexAttribute(0, vertex_number * sizeof(float), (void*)0);
    } else if (settings.with_color) {
        // Координатный атрибут
        setVertexAttribute(0, vertex_number * 2 * sizeof(float), (void*)0);
        // Цветовой атрибут
        setVertexAttribute(1, vertex_number * 2 * sizeof(float), (void*)(vertex_number * sizeof(float)));
    }
}

unsigned int Primitive::getUid() const {
    return VBO;
}

void Primitive::setVertexAttribute(const int& index, const int& size, void* offset) {
    glVertexAttribPointer(index, vertex_number, GL_FLOAT, GL_FALSE, size, offset);
    glEnableVertexAttribArray(index);
}
