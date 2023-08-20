//
// Created by VerOchka on 19.08.2023.
//

#include "Texture.hpp"

Texture::Texture(unsigned int id) : _id(id) {
    glGenTextures(1, &_texture);
}

bool Texture::bind2d(const char source[]) const {
    bool res = false;

    glBindTexture(GL_TEXTURE_2D, _texture);

    // Устанавливаем параметры наложения и фильтрации текстур (для текущего связанного объекта текстуры)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(source, &width, &height, &nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
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
