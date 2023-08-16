//
// Created by VerOchka on 16.08.2023.
//

#include "Primitive.hpp"

Primitive::Primitive(std::shared_ptr<ShaderProgram> shader_program, const int& vertex_number_) : shader_program(shader_program), vertex_number(vertex_number_) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    drawCallback = [](){};
}

void Primitive::setDrawCallback(std::function<void()> function) {
    drawCallback = std::move(function);
}

void Primitive::bindVerticesToCoordinates(std::vector<float> coordinates,  const Settings& settings) {
    if (coordinates.size() > vertex_number * 3)
        throw std::exception(std::format("Wrong number of coordinates: {} when need {}\n", coordinates.size(), vertex_number *3).c_str());

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_number * 3 * sizeof(float), coordinates.data(), bind_flag);

    glVertexAttribPointer(0, vertex_number, GL_FLOAT, GL_FALSE, vertex_number * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Primitive::bindVerticesToCoordinatesAndColor(std::vector<float> coordinates, const unsigned int& bind_flag) {
    int elements_count = vertex_number * 3 * 2;
    if (coordinates.size() > elements_count)
        throw std::exception(std::format("Wrong number of coordinates: {} when need {}\n", coordinates.size(), elements_count).c_str());

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_number * 3 * 2 * sizeof(float), coordinates.data(), bind_flag);

    // Координатный атрибут
    glVertexAttribPointer(0, vertex_number, GL_FLOAT, GL_FALSE, vertex_number * 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Цветовой атрибут
    glVertexAttribPointer(1,
                          vertex_number, GL_FLOAT, GL_FALSE,
                          vertex_number * 2 * sizeof(float), (void*)(vertex_number * sizeof(float)));
    glEnableVertexAttribArray(1);
}

unsigned int Primitive::getUid() const {
    return VBO;
}
