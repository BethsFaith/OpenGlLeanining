//
// Created by VerOchka on 26.08.2023.
//

#ifndef INC_2_SHADERS_CUBE_HPP
#define INC_2_SHADERS_CUBE_HPP

#include "BasePrimitive.hpp"
#include "buffers/Ebo.hpp"
#include "buffers/Vbo.hpp"

namespace Tools::Objects::Faces {
    class Cube : public BasePrimitive {
    public:
        explicit Cube(const Settings &settings);

        ~Cube() override = default;

        void draw() override;

    private:
        static std::vector<glm::vec3> getPosition();
        static std::vector<glm::vec3> getNormals();
        static std::vector<glm::vec2> getTextureCoordinates();
    };
}

#endif    //INC_2_SHADERS_CUBE_HPP
