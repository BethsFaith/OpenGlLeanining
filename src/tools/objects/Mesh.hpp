//
// Created by VerOchka on 18.09.2023.
//

#ifndef INC_2_SHADERS_MESH_HPP
#define INC_2_SHADERS_MESH_HPP

#include "../shaders/ShaderProgram.hpp"
#include "faces/Primitive.hpp"
#include "faces/buffers/Ebo.hpp"
#include "faces/buffers/Vbo.hpp"
#include "textures/Loader.hpp"

namespace Tools::Objects {
    class Mesh : public Faces::Primitive{
    public:
        Mesh(const std::vector<Faces::Buffers::Vertex> &vertices, const std::vector<unsigned int> &indices,
             const std::vector<Textures::Texture::Ptr>& textures);

        ~Mesh() override = default;

        void draw(const std::shared_ptr<Shaders::ShaderProgram>& shader);

        void bindData(const unsigned int& bind_flag) override;

    private:
        void draw() override;

        std::vector<Textures::Texture::Ptr> _textures;
    };
}

#endif    //INC_2_SHADERS_MESH_HPP
