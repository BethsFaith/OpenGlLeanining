//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_BASEPRIMITIVE_HPP
#define INC_2_SHADERS_BASEPRIMITIVE_HPP

#include <algorithm>
#include <format>
#include <functional>
#include <vector>

#include "AbstractPrimitive.hpp"
#include "Settings.hpp"
#include "buffers/Vao.hpp"
#include "buffers/Vertex.hpp"

namespace Tools::Objects::Faces {
    class BasePrimitive : public AbstractPrimitive {
    public:
        explicit BasePrimitive(const int& vertex_number, const Settings &settings);
        ~BasePrimitive() override = default;

        void setDrawCallback(std::function<void()> function) override;

        void bind(const unsigned int& bind_flag) override;
        void draw() override;

        [[nodiscard]] unsigned int getUid() const override;

    protected:
        void add(std::shared_ptr<Buffers::RaiiBuffer> raii_buffer);

        virtual void setVertexAttribute(const int& index, const int& size, const int& stride, void* offset);

        std::vector<std::shared_ptr<Buffers::RaiiBuffer>> buffers{};

        std::function<void()> drawCallback;

        const int vertex_number;

        std::vector<Buffers::Vertex> vertices;
        std::vector<unsigned int> indices;
    private:
        std::shared_ptr<Buffers::VAO> _vao;

        Settings _settings;
    };
}

#endif    //INC_2_SHADERS_BASEPRIMITIVE_HPP
