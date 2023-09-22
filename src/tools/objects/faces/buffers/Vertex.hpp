//
// Created by VerOchka on 18.09.2023.
//

#ifndef INC_2_SHADERS_VERTEX_HPP
#define INC_2_SHADERS_VERTEX_HPP

#include "../../libHeadears/glm.hpp"
#include <glad/glad.h>

namespace Tools::Objects::Faces::Buffers {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tex_coords;

        // Касательный вектор
        glm::vec3 tangent;
        // Вектор бинормали (вектор, перпендикулярный касательному вектору и вектору нормали)
        glm::vec3 bitangent;
    };

    void setVertexAttribute(const int& index, const int& size, const int& stride, void* offset);

    //    template <typename TField>
    //    void setVertexAttribute(const int& index, void* offset) {
    //        int size;
    //        if (typeid(TField) == typeid(glm::vec3)){
    //            size = 3;
    //        } else if (typeid(TField) == typeid(glm::vec2)) {
    //            size = 2;
    //        } else {
    //            throw std::runtime_error("Wrong Type of Vertex");
    //        }
    //
    //        setVertexAttribute(index,
    //                           size,
    //                           (int)(sizeof(Vertex)),
    //                           offset);
    //    }
}

#endif    //INC_2_SHADERS_VERTEX_HPP
