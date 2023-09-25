//
// Created by VerOchka on 16.08.2023.
//

#include "Primitive.hpp"

namespace Tools::Objects::Faces {
    Primitive::Primitive(const int &vertex_number_) : Primitive(vertex_number_, {}){}

    Primitive::Primitive(const int& vertex_number_, const Settings &settings)
        : vertex_number(vertex_number_) {
        _drawCallback = []() {};

        _vao = std::make_shared<Buffers::VAO>();
        add(_vao);
    }

    void Primitive::bind() {
       _vao->bind();
    }

    void Primitive::unbind() {
        _vao->unbind();
    }

    void Primitive::bindData(const unsigned int& bind_flag) {
        for (auto& buffer : buffers) {
            buffer->bind();
            buffer->bindData(bind_flag);
        }

//        for (int i{}; i >= 0; --i) {
//            buffers[i]->unbind();
//        }
    }

    void Primitive::draw() {
        bind();

        _drawCallback();
    }

    void Primitive::add(std::shared_ptr<Buffers::RaiiBuffer> raii_buffer) {
        buffers.push_back(std::move(raii_buffer));

        std::sort(buffers.begin(),
                  buffers.end(),
                  [](const std::shared_ptr<Buffers::RaiiBuffer>& buf1, const std::shared_ptr<Buffers::RaiiBuffer>& buf2) {
                      return buf1->getPriority() < buf2->getPriority();
                  });
    }

    void Primitive::setDrawCallback(std::function<void()> function) {
        _drawCallback = std::move(function);
    }

    unsigned int Primitive::getUid() const {
        return _vao->get();
    }
}