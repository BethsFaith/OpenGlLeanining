//
// Created by VeraTag on 20.09.2023.
//

#ifndef INC_2_SHADERS_MODEL_HPP
#define INC_2_SHADERS_MODEL_HPP

#include "Mesh.hpp"
#include "../shaders/ShaderProgram.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Tools::Objects {
    class Model {
    public:
        explicit Model(const std::string &path);
        ~Model() = default;

        void draw(const std::shared_ptr<Shaders::ShaderProgram> &shader);
        void draw();

        void setShaderProgram(const std::shared_ptr<Shaders::ShaderProgram>& shader);
    private:
        void loadModel(const std::string& path);

        std::vector<Textures::TextureWorker> loadMaterialTextures(aiMaterial *mat, const aiTextureType& type,
                                                            const std::string& typeName);

        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);

        std::vector<Mesh> _meshes;
        std::string _directory;
    };
}

#endif //INC_2_SHADERS_MODEL_HPP
