//
// Created by VerOchka on 22.09.2023.
//

#include "Texture.hpp"

#include <utility>

namespace Tools::Objects::Textures {
    Texture::Texture(std::string  name, std::string  path) : _name(std::move(name)), _path(std::move(path)) {
        glGenTextures(1, &_id);
    }

    Texture::~Texture() {
        glDeleteTextures(1, &_id);
    }

    void Texture::activate() const {
        glActiveTexture(_id);
        glBindTexture(GL_TEXTURE_2D, _id);
    }

    void Texture::deactivate() {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    unsigned int Texture::getId() const {
        return _id;
    }

    const std::string& Texture::getName() const {
        return _name;
    }

    const std::string& Texture::getPath() const {
        return _path;
    }
}
