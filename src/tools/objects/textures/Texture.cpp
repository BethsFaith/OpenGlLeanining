//
// Created by VerOchka on 22.09.2023.
//

#include "Texture.hpp"

#include <utility>

namespace Tools::Objects::Textures {
    Texture::Texture(std::string name, std::string path, GLenum type) : _name(std::move(name)), _path(std::move(path)), _type(type) {
        glGenTextures(1, &_id);
    }

    Texture::~Texture() {
        glDeleteTextures(1, &_id);
    }

    void Texture::activate(unsigned int gl_int) const {
        glActiveTexture(gl_int);
        glBindTexture(_type, _id);
    }

    void Texture::deactivate() const {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(_type, 0);
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

    GLenum Texture::getType() const {
        return _type;
    }
}
