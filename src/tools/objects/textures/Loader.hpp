//
// Created by VerOchka on 19.08.2023.
//

#ifndef INC_2_SHADERS_LOADER_HPP
#define INC_2_SHADERS_LOADER_HPP

#include <iostream>
#include <stb_image.h>
#include <vector>

#include "Texture.hpp"

namespace Tools::Objects::Textures::Loader {
    struct Param {
        GLenum name;
        GLint value;
    };

    bool load2d(Texture& texture, const std::vector<Param>& params);
    bool loadCubeMap2d(std::vector<Texture::Ptr>& textures_faces, const std::vector<Param>& params);
}

#endif    //INC_2_SHADERS_LOADER_HPP
