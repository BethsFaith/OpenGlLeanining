//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_RECTANGLE_HPP
#define INC_2_SHADERS_RECTANGLE_HPP

#include "Primitive.hpp"
#include "buffers/Ebo.hpp"
#include "buffers/Vbo.hpp"

namespace Tools::Objects::Faces {
    class Rectangle : public Primitive {
    public:
        explicit Rectangle(const Settings &settings);

        ~Rectangle() override = default;
        void draw() override;

    private:
        static std::vector<glm::vec3> getPosition();
        static std::vector<glm::vec3> getNormals();
        static std::vector<glm::vec2> getTextureCoordinates();

    protected:
        void bindData(const unsigned int& bind_flag) override;
    };
}

#endif    //INC_2_SHADERS_RECTANGLE_HPP
