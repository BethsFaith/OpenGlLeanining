//
// Created by VerOchka on 16.08.2023.
//

#include "Drawer.hpp"

namespace Tools {
    void Drawer::addPrimitive(const std::shared_ptr<Tools::Objects::Faces::BasePrimitive>& primitive,
                              const std::shared_ptr<Tools::Shaders::ShaderProgram>& shader_program) {
        _primitives.push_back(DrawablePrimitive{.primitive = primitive, .shader = shader_program});
    }

    void Drawer::removePrimitive(std::shared_ptr<Tools::Objects::Faces::BasePrimitive> primitive) {
        auto elem = std::find_if(_primitives.begin(), _primitives.end(),
                                 [&](const DrawablePrimitive &elem) {
            return elem.primitive->getUid() == primitive->getUid();
        });

        _primitives.erase(elem);
    }

    void Drawer::removePrimitive(const unsigned int& uid) {
        auto elem = std::find_if(_primitives.begin(), _primitives.end(),
                                 [&](const DrawablePrimitive &elem) {
                                     return elem.primitive->getUid() == uid;
                                 });

        _primitives.erase(elem);
    }

    void Drawer::draw() {
        for (const auto& drawable_primitive : _primitives) {
            drawable_primitive.shader->use();
            drawable_primitive.primitive->draw();
        }
    }
}