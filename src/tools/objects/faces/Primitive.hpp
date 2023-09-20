//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_PRIMITIVE_HPP
#define INC_2_SHADERS_PRIMITIVE_HPP

#include <algorithm>
#include <format>
#include <functional>
#include <vector>

#include "AbstractPrimitive.hpp"
#include "Settings.hpp"
#include "buffers/Vao.hpp"
#include "buffers/Vertex.hpp"

namespace Tools::Objects::Faces {
    class Primitive : public AbstractPrimitive {
    public:
        explicit Primitive(const int& vertex_number);
        explicit Primitive(const int& vertex_number, const Settings &settings);
        ~Primitive() override = default;

        void setDrawCallback(std::function<void()> function) override;

        void bind(const unsigned int& bind_flag) override;
        void draw() override;

        [[nodiscard]] unsigned int getUid() const override;

    protected:
        void add(std::shared_ptr<Buffers::RaiiBuffer> raii_buffer);

        virtual void setVertexAttribute(const int& index, const int& size, const int& stride, void* offset);

        std::vector<std::shared_ptr<Buffers::RaiiBuffer>> buffers{};

        const int vertex_number;

        std::vector<Buffers::Vertex> vertices;
        std::vector<unsigned int> indices;
    private:
        std::function<void()> _drawCallback;

        std::shared_ptr<Buffers::VAO> _vao;

        Settings _settings;
    };
}

#endif    //INC_2_SHADERS_PRIMITIVE_HPP
