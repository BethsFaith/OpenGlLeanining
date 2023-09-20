//
// Created by VerOchka on 18.09.2023.
//

#include "Mesh.hpp"
namespace Tools::Objects {
    Mesh::Mesh(const std::vector<Faces::Buffers::Vertex> &vertices_, const std::vector<unsigned int> &indices_,
                               const std::vector<Textures::TextureWorker> &textures,
                               const std::shared_ptr<Shaders::ShaderProgram> &shader)
            : Faces::Primitive((int)vertices_.size()),
              _textures(textures),
              _shader(shader) {
        indices = indices_;
        vertices = vertices_;

        add(std::make_shared<Faces::Buffers::VBO>(vertices));
        add(std::make_shared<Faces::Buffers::EBO>(indices));
    }

    void Mesh::draw() {
        Primitive::draw();

        _shader->use();

        unsigned int diffuse_number = 1;
        unsigned int specular_number = 1;

        for (unsigned int i = 0; i < (int)_textures.size(); ++i) {
            _textures.at(i).activate();

            std::string number;
            std::string name = _textures[i].getTextureData().name;

            if (name == "texture_diffuse") {
                number = std::to_string(diffuse_number++);
            } else if (name == "specular_diffuse"){
                number = std::to_string(specular_number++);
            } else {
                std::cout << "ERROR: NAME OF TEXTURE UNKNOWN" << std::endl;
            }

            // в шейдер засунуть текстуру
            _shader->setFloat("material." + name + number, (float)i);
        }
        Textures::TextureWorker::deactivate();

        glDrawElements(GL_TRIANGLES, (int)indices.size(), GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }

    void Mesh::bind(const unsigned int &bind_flag) {
        Primitive::bind(bind_flag);
    }
}
