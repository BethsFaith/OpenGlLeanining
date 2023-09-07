//
// Created by VerOchka on 19.08.2023.
//

#include "Texture.hpp"

namespace Figures {
    Texture::Texture(unsigned int id) : _id(id) {
        glGenTextures(1, &_texture);
    }

    bool Texture::bind2d(const char source[]) const {
        bool res = false;

        glBindTexture(GL_TEXTURE_2D, _texture);

        for (const auto& param : _params) {
            glTexParameteri(param.target, param.name, param.value);
        }

        stbi_set_flip_vertically_on_load(true);
        int width, height, nrChannels;
        unsigned char* data = stbi_load(source, &width, &height, &nrChannels, 0);

        if (data) {
            int flag = (nrChannels == 3 ? GL_RGB : GL_RGBA);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, flag, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            res = true;
        } else {
            std::cout << "Failed to load texture\n" << std::endl;
        }

        stbi_image_free(data);
        return res;
    }

    void Texture::bind() const {
        glActiveTexture(_id);
        glBindTexture(GL_TEXTURE_2D, _texture);
    }

    void Texture::addParam(Texture::Param param) {
        _params.push_back(param);
    }
}    //namespace Figures
