//
// Created by VerOchka on 19.08.2023.
//

#include "Loader.hpp"

#include <utility>

namespace Tools::Objects::Textures::Loader {
    bool load2d(Texture& texture, const std::vector<Param>& params) {
        bool res = false;

                stbi_set_flip_vertically_on_load(true);
        int width, height, nrChannels;
        unsigned char* data = stbi_load(texture.getPath().c_str(), &width, &height, &nrChannels, 0);

        if (data) {
            GLenum format;
            if (nrChannels == 1) {
                format = GL_RED;
            } else if (nrChannels == 3) {
                format = GL_RGB;
            } else if (nrChannels == 4) {
                format = GL_RGBA;
            }

            glBindTexture(GL_TEXTURE_2D, texture.getId());
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            for (const auto& param : params) {
                glTexParameteri(GL_TEXTURE_2D, param.name, param.value);
            }

            res = true;
        } else {
            std::cout << "Failed to load texture\n" << std::endl;
        }

        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);

        return res;
    }

    bool loadCubeMap2d(Texture& texture,
                       std::vector<std::string> texture_faces_path,
                       const std::vector<Param>& params) {
        bool res = false;

        glBindTexture(GL_TEXTURE_CUBE_MAP, texture.getId());

        int width, height, nrChannels;
        unsigned char* data;

        for (int i = 0; i < texture_faces_path.size(); i++) {
            data = stbi_load((texture.getPath() + texture_faces_path.at(i)).c_str(),
                             &width, &height, &nrChannels, 0);

            if (data) {
                GLenum format;
                if (nrChannels == 1) {
                    format = GL_RED;
                } else if (nrChannels == 3) {
                    format = GL_RGB;
                } else if (nrChannels == 4) {
                    format = GL_RGBA;
                }

                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                             0,
                             format,
                             width,
                             height,
                             0,
                             format,
                             GL_UNSIGNED_BYTE,
                             data);

                res = true;

            } else {
                std::cout << "Failed to load texture\n" << std::endl;
            }

            stbi_image_free(data);
        }

        for (const auto& param : params) {
            glTexParameteri(GL_TEXTURE_CUBE_MAP, param.name, param.value);
        }

        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

        return res;
    }
}    //namespace Tools::Objects::Textures::Loader
