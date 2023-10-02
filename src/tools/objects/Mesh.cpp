//
// Created by VerOchka on 18.09.2023.
//

#include "Mesh.hpp"
namespace Tools::Objects {
    Mesh::Mesh(const std::vector<Faces::Buffers::Vertex> &vertices, const std::vector<unsigned int> &indices,
                               const std::vector<Textures::Texture::Ptr> &textures)
            : Faces::Primitive((int)vertices.size()),
              _textures(textures) {
        add(std::make_shared<Faces::Buffers::VBO<Faces::Buffers::Vertex>>(vertices));
        add(std::make_shared<Faces::Buffers::EBO>(indices));
    }

    void Mesh::draw(const std::shared_ptr<Shaders::ShaderProgram>& shader) {
        Primitive::draw();

        if (shader != nullptr) {
            shader->use();

            unsigned int diffuse_number = 1;
            unsigned int specular_number = 1;
            unsigned int normal_number = 1;
            unsigned int height_number = 1;

            for (unsigned int i = 0; i < (int)_textures.size(); ++i) {
                std::string number;
                std::string name = _textures[i]->getName();

                if (name == "texture_diffuse") {
                    number = std::to_string(diffuse_number++);
                } else if (name == "texture_specular"){
                    number = std::to_string(specular_number++);
                }  else if (name == "texture_normal") {
                    number = std::to_string(normal_number++); // конвертируем unsigned int в строку
                } else if (name == "texture_height") {
                    number = std::to_string(height_number++);    // конвертируем unsigned int в строку
                } else {
                    std::cout << "ERROR: NAME OF TEXTURE UNKNOWN" << std::endl;
                    continue;
                }

                // в шейдер засунуть текстуру
                shader->setInt("material." + name + number, i);
                _textures.at(i)->activate(GL_TEXTURE0 + i);
            }
        }

        draw();

        std::vector<GLenum> deactivated_types;
        for (const auto& texture : _textures) {
            auto type = texture->getType();

            if (std::find(deactivated_types.begin(), deactivated_types.end(), type) != deactivated_types.end()) {
                texture->deactivate();
                deactivated_types.push_back(type);
            }
        }

        Primitive::unbind();
    }

    void Mesh::bindData(const unsigned int& bind_flag) {
        Primitive::bindData(bind_flag);

        bind();

        using namespace Faces;
        int index = 0;

        Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, position));
        if (settings.with_normals) {
            Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, normal));
        }
        if (settings.with_texture) {
            Buffers::setVertexAttribute(index++, 2, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, tex_coords));
        }
        if (settings.with_tangent) {
            Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, tangent));
        }
        if (settings.with_bitangent) {
            Buffers::setVertexAttribute(index++, 3, (int)(sizeof(Buffers::Vertex)), (void*)offsetof(Buffers::Vertex, bitangent));
        }

        unbind();
    }

    void Mesh::draw() {
        Primitive::draw();

        glDrawElements(GL_TRIANGLES, (int)vertex_number, GL_UNSIGNED_INT, 0);
    }
}
