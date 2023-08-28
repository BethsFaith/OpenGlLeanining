//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_PRIMITIVE_HPP
#define INC_2_SHADERS_PRIMITIVE_HPP

#include <functional>
#include <vector>
#include <format>
#include <algorithm>

#include "shaders/ShaderProgram.hpp"
#include "Settings.hpp"
#include "buffers/Vao.hpp"

class Primitive {
public:
    explicit Primitive(const std::shared_ptr<ShaderProgram>& shader_program, const int& vertex_number);
    virtual ~Primitive() = default;

    virtual void setDrawCallback(std::function<void()> function);

    virtual void bind(const Settings& settings);
    virtual void draw();

    [[nodiscard]] unsigned int getUid() const;
protected:
    void add(std::shared_ptr<RaiiBuffer> raii_buffer);

    virtual void setVertexAttribute(const int& index, const int& size, const int& stride, void* offset);

    const int vertex_number;

    std::vector<std::shared_ptr<RaiiBuffer>> buffers{};

    std::shared_ptr<ShaderProgram> shader_program;
    std::function<void()> drawCallback;

    int vertices_attribute_numbers;
private:
};

#endif    //INC_2_SHADERS_PRIMITIVE_HPP
