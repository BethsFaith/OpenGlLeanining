//
// Created by VeraTag on 20.09.2023.
//

#ifndef INC_2_SHADERS_MODEL_HPP
#define INC_2_SHADERS_MODEL_HPP

#include "Mesh.hpp"
#include "../shaders/ShaderProgram.hpp"

namespace Tools::Objects {
    class Model
    {
    public:
        explicit Model(const std::string &path);
        ~Model() = default;

        void draw(const std::shared_ptr<Shaders::ShaderProgram> &shader);

    private:
        void loadModel(const std::string& path);
        void processNode();

        std::vector<Mesh> _meshes;
    };
}

#endif //INC_2_SHADERS_MODEL_HPP
