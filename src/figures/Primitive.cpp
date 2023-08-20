//
// Created by VerOchka on 16.08.2023.
//

#include "Primitive.hpp"

Primitive::Primitive(const std::shared_ptr<ShaderProgram>& shader_program, const int& vertex_number_)
    : shader_program(shader_program),
      vertex_number(vertex_number_) {

    vertices_attribute_numbers = vertex_number;

    drawCallback = []() {};

    add(std::make_shared<VAO>());
}

void Primitive::setDrawCallback(std::function<void()> function) {
    drawCallback = std::move(function);
}

void Primitive::bind(const Settings& settings) {
    for (auto& buffer : buffers) {
        buffer->bind(settings.bind_flag);
    }

    int number = vertices_attribute_numbers;
    if (settings.with_color) {
        number += 3;
    }
    if (settings.with_texture) {
        number += 2;
    }

    int index = 0;
    // Координатный атрибут
    setVertexAttribute(index++,
                       3,
                       (int)(number * sizeof(float)),
                       (void*)nullptr);

    if (settings.with_color) {
        // Цветовой атрибут
        setVertexAttribute(index++,
                           3,
                           (int)(number * sizeof(float)),
                           (void*)(vertices_attribute_numbers * sizeof(float)));
    }
    if (settings.with_texture) {
        setVertexAttribute(index++,
                           2,
                           (int)(number * sizeof(float)),
                           (void*)(vertices_attribute_numbers * 2 * sizeof(float)));
    }
}

unsigned int Primitive::getUid() const {
    return buffers[0]->get();
}

void Primitive::setVertexAttribute(const int& index, const int& size, const int& stride, void* offset) {
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
}

void Primitive::add(std::shared_ptr<RaiiBuffer> raii_buffer) {
    buffers.push_back(std::move(raii_buffer));

    std::sort(buffers.begin(), buffers.end(), [](const std::shared_ptr<RaiiBuffer>& buf1, const std::shared_ptr<RaiiBuffer>& buf2){
        return buf1->getPriority() < buf2->getPriority();
    });
}

void Primitive::draw() {
    glBindVertexArray(buffers[0]->get());

    shader_program->use();

    drawCallback();
}
