//
// Created by VerOchka on 18.09.2023.
//

#ifndef INC_2_SHADERS_MESH_HPP
#define INC_2_SHADERS_MESH_HPP

#include "../shaders/ShaderProgram.hpp"
#include "faces/buffers/Ebo.hpp"
#include "faces/buffers/Vao.hpp"
#include "faces/buffers/Vbo.hpp"
#include "faces/buffers/Vertex.hpp"
#include "textures/TextureWorker.hpp"

namespace Tools::Objects {
    class Mesh {
    public:
        Mesh(const std::vector<Textures::TextureWorker>& textures);

        void Draw(const Shaders::ShaderProgram& shader_program);
    private:
        std::vector<Textures::TextureWorker> _textures;
    };
}

#endif    //INC_2_SHADERS_MESH_HPP
