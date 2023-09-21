//
// Created by VerOchka on 18.09.2023.
//

#ifndef INC_2_SHADERS_MESH_HPP
#define INC_2_SHADERS_MESH_HPP

#include "faces/Primitive.hpp"
#include "faces/buffers/Vbo.hpp"
#include "faces/buffers/Ebo.hpp"
#include "textures/TextureWorker.hpp"
#include "../shaders/ShaderProgram.hpp"

namespace Tools::Objects {
    class Mesh : public Faces::Primitive {
    public:
        Mesh(const std::vector<Faces::Buffers::Vertex> &vertices, const std::vector<unsigned int> &indices,
             const std::vector<Textures::TextureWorker>& textures);

        ~Mesh() override = default;

        void draw() override;

        void setShader(const std::shared_ptr<Shaders::ShaderProgram> &shader);

    protected:
        void bind(const unsigned int &bind_flag) override;

    private:
        std::vector<Textures::TextureWorker> _textures;
        std::shared_ptr<Shaders::ShaderProgram> _shader;
    };
}

#endif    //INC_2_SHADERS_MESH_HPP
