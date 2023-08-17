//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_PRIMITIVE_HPP
#define INC_2_SHADERS_PRIMITIVE_HPP

#include <functional>
#include <vector>
#include <format>

#include "shaders/ShaderProgram.hpp"
#include "Settings.hpp"

class Primitive {
public:
    explicit Primitive(std::shared_ptr<ShaderProgram> shader_program, const int& vertex_number);

    virtual void setDrawCallback(std::function<void()> function);

    virtual void bindVerticesToCoordinates(std::vector<float> coordinates, const Settings& settings);
    virtual void draw() = 0;

    unsigned int getUid() const;
protected:
    void setVertexAttribute(const int& index, const int& size, void* offset);

    const int vertex_number;

    unsigned int VBO{};
    unsigned int VAO{};

    std::shared_ptr<ShaderProgram> shader_program;
    std::function<void()> drawCallback;

private:
    int *size;
};

#endif    //INC_2_SHADERS_PRIMITIVE_HPP
