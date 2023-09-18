//
// Created by VerOchka on 18.09.2023.
//

#include "Mesh.hpp"
namespace Tools::Objects {

    Mesh::Mesh(const std::vector<Textures::TextureWorker>& textures)
        : _textures(textures) {
    }

    void Mesh::Draw(const Shaders::ShaderProgram& shader_program) {}
}