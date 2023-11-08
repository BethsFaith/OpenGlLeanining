//
// Created by VeraTag on 20.09.2023.
//

#include "Model.hpp"

namespace Tools::Objects {
    Model::Model(const std::string& path_to_model) {
        loadModel(path_to_model);
        textures_loaded.clear();
    }

    void Model::loadModel(const std::string& path) {
        Assimp::Importer importer;
        const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs
                                                           | aiProcess_CalcTangentSpace);

        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
            return;
        }
        _directory = path.substr(0, path.find_last_of('/'));

        processNode(scene->mRootNode, scene);
    }

    void Model::processNode(aiNode* node, const aiScene* scene) {
        // Обрабатываем все меши (если они есть) у выбранного узла
        for(unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh *ai_mesh = scene->mMeshes[node->mMeshes[i]];

            auto mesh = processMesh(ai_mesh, scene);
            mesh.bindData(GL_STATIC_DRAW);

            _meshes.push_back(mesh);
        }
        // И проделываем то же самое для всех дочерних узлов
        for(unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

    Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
        std::vector<Faces::Buffers::Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Textures::Texture::Ptr> textures;

        for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
            Faces::Buffers::Vertex vertex{};
            // Обрабатываем координаты вершин, нормали и текстурные координаты
            glm::vec3 vector;

            vector.x = mesh->mVertices[i].x;
            vector.y = mesh->mVertices[i].y;
            vector.z = mesh->mVertices[i].z;
            vertex.position = vector;

            if (mesh->mNormals != nullptr) {
                vector.x = mesh->mNormals[i].x;
                vector.y = mesh->mNormals[i].y;
                vector.z = mesh->mNormals[i].z;
                vertex.normal = vector;
            } else {
                vertex.normal = {};
            }

            if (mesh->mTextureCoords[0]) {    // действительно ли меш содержит текстурные координаты?
                glm::vec2 vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.tex_coords = vec;
            } else {
                vertex.tex_coords = glm::vec2(0.0f, 0.0f);
            }
            if (mesh->mTangents != nullptr) {
                // Касательный вектор
                vector.x = mesh->mTangents[i].x;
                vector.y = mesh->mTangents[i].y;
                vector.z = mesh->mTangents[i].z;
                vertex.tangent = vector;
            } else {
                vertex.tangent = {};
            }
            if (mesh->mBitangents != nullptr) {
                // Вектор бинормали
                vector.x = mesh->mBitangents[i].x;
                vector.y = mesh->mBitangents[i].y;
                vector.z = mesh->mBitangents[i].z;
                vertex.bitangent = vector;
                vertices.push_back(vertex);
            } else {
                vertex.bitangent = {};
            }
        }

        // Обрабатываем индексы
        for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];

            for(unsigned int j = 0; j < face.mNumIndices; j++) {
                indices.push_back(face.mIndices[j]);
            }
        }

        // Обрабатываем материал
        if(mesh->mMaterialIndex >= 0) {
            aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

            // 1. Диффузные карты
            std::vector<Textures::Texture::Ptr> diffuseMaps = loadMaterialTextures(material,
                                                                                   aiTextureType_DIFFUSE,
                                                                                   "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

            // 2. Карты отражения
            std::vector<Textures::Texture::Ptr> specularMaps = loadMaterialTextures(material,
                                                                                    aiTextureType_SPECULAR,
                                                                                    "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

            // 3. Карты нормалей
            std::vector<Textures::Texture::Ptr> normalMaps = loadMaterialTextures(material,
                                                                                  aiTextureType_HEIGHT,
                                                                                  "texture_normal");
            textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

            // 4. Карты высот
            std::vector<Textures::Texture::Ptr> heightMaps = loadMaterialTextures(material,
                                                                                  aiTextureType_AMBIENT,
                                                                                  "texture_height");
            textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
        }

        return {vertices, indices, textures};
    }

    std::vector<Textures::Texture::Ptr> Model::loadMaterialTextures(aiMaterial* mat,
                                                               const aiTextureType& type,
                                                               const std::string& typeName) {
        std::vector<Textures::Texture::Ptr> textures;

        for(unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
            aiString str;
            mat->GetTexture(type, i, &str);

            std::string path(str.C_Str());
            path = _directory + "/" + path;

            bool skip = false;
            for(const auto& loaded : textures_loaded) {
                if(std::strcmp(loaded->getPath().data(), path.data()) == 0) {
                    textures.push_back(loaded);
                    skip = true;
                    break;
                }
            }

            if (!skip) {
                auto texture = std::make_shared<Textures::Texture>(typeName, path);

                Textures::Loader::load2d(*texture, {
                                              {.name = GL_TEXTURE_WRAP_S,
                                               .value =  GL_REPEAT},
                                              {.name = GL_TEXTURE_WRAP_T,
                                               .value = GL_REPEAT},
                                              {.name = GL_TEXTURE_MIN_FILTER,
                                               .value =  GL_LINEAR_MIPMAP_LINEAR},
                                              {.name = GL_TEXTURE_MAG_FILTER,
                                               .value =  GL_LINEAR}
                                          });

                textures.push_back(texture);
                textures_loaded.push_back(texture);
            }
        }
        return textures;
    }

    void Model::draw(const std::shared_ptr<Shaders::ShaderProgram>& shader) {
        for (auto mesh : _meshes) {
            mesh.draw(shader);
        }
    }
}