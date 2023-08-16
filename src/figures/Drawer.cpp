//
// Created by VerOchka on 16.08.2023.
//

#include "Drawer.hpp"

void Drawer::addPrimitive(const std::shared_ptr<Primitive>& primitive) {
    _primitives.push_back(primitive);
}

void Drawer::removePrimitive(std::shared_ptr<Primitive> primitive) {
    auto elem = std::find_if(_primitives.begin(), _primitives.end(), [&](const std::shared_ptr<Primitive>& elem){
        return elem->getUid() == primitive->getUid();
    });

    _primitives.erase(elem);
}

void Drawer::draw() {
    for (const auto& primitive : _primitives){
        primitive->draw();
    }
}
