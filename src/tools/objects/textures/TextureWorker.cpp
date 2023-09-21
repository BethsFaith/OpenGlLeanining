//
// Created by VerOchka on 19.08.2023.
//

#include "TextureWorker.hpp"

#include <utility>

namespace Tools::Objects::Textures {
    TextureWorker::TextureWorker(unsigned int id, std::string name) : _textureData(Texture{.id = id, .name = std::move(name)}) {
        glGenTextures(1, &_texture);
    }

    bool TextureWorker::bind2d(const char source[]) {
        bool res = false;

        _textureData.path = source;

        for (const auto& param : _params) {
            glTexParameteri(param.target, param.name, param.value);
        }

        stbi_set_flip_vertically_on_load(true);
        int width, height, nrChannels;
        unsigned char* data = stbi_load(source, &width, &height, &nrChannels, 0);

        if (data) {
            GLenum format;
            if (nrChannels == 1)
                format = GL_RED;
            else if (nrChannels == 3)
                format = GL_RGB;
            else if (nrChannels == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, _texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            res = true;
        } else {
            std::cout << "Failed to load texture\n" << std::endl;
        }

        stbi_image_free(data);
        return res;
    }

    void TextureWorker::activate() const {
        glActiveTexture(_textureData.id);
        glBindTexture(GL_TEXTURE_2D, _texture);
    }

    void TextureWorker::deactivate() {
        glActiveTexture(GL_TEXTURE0);
    }

    void TextureWorker::addParam(TextureWorker::Param param) {
        _params.push_back(param);
    }

    const Texture& TextureWorker::getTextureData() const {
        return _textureData;
    }
}    //namespace Figures
