//
// Created by VerOchka on 18.09.2023.
//

#ifndef INC_2_SHADERS_VERTEX_HPP
#define INC_2_SHADERS_VERTEX_HPP

#include "../../libHeadears/glm.hpp"

namespace Tools::Objects::Faces::Buffers {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tex_coords;
    };
}

#endif    //INC_2_SHADERS_VERTEX_HPP
