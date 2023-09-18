//
// Created by VerOchka on 19.08.2023.
//

#include "TextureWorker.hpp"

#include <utility>

namespace Tools::Objects::Textures {
    TextureWorker::TextureWorker(unsigned int id, std::string name) : _textureData(Texture{.id = id, .name = std::move(name)}) {
        glGenTextures(1, &_texture);
    }

    bool TextureWorker::bind2d(const char source[]) const {
        bool res = false;

        for (const auto& param : _params) {
            glTexParameteri(param.target, param.name, param.value);
        }

        stbi_set_flip_vertically_on_load(true);
        int width, height, nrChannels;
        unsigned char* data = stbi_load(source, &width, &height, &nrChannels, 0);

        if (data) {
            int flag = (nrChannels == 3 ? GL_RGB : GL_RGBA);

            glBindTexture(GL_TEXTURE_2D, _texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, flag, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            res = true;
        } else {
            std::cout << "Failed to load texture\n" << std::endl;
        }

        stbi_image_free(data);
        return res;
    }

    void TextureWorker::bind() const {
        glActiveTexture(_textureData.id);
        glBindTexture(GL_TEXTURE_2D, _texture);
    }

    void TextureWorker::addParam(TextureWorker::Param param) {
        _params.push_back(param);
    }

    const Texture& TextureWorker::getTextureData() const {
        return _textureData;
    }
}    //namespace Figures
