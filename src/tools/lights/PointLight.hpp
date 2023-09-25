//
// Created by VerOchka on 25.09.2023.
//

#ifndef INC_2_SHADERS_POINTLIGHT_HPP
#define INC_2_SHADERS_POINTLIGHT_HPP

#include "../objects/libHeadears/glm.hpp"
#include "SerializableLight.hpp"

namespace Tools::Lights {
    class PointLight : public SerializableLight {
    public:
        PointLight() = default;
        ~PointLight() override = default;

        void serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) override;

        void setPosition(const glm::vec3& position);
        void setConstant(float constant);
        void setLinear(float linear);
        void setQuadratic(float quadratic);
        void setAmbient(const glm::vec3& ambient);
        void setDiffuse(const glm::vec3& diffuse);
        void setSpecular(const glm::vec3& specular);

    private:
        glm::vec3 _position{};

        float _constant{};
        float _linear{};
        float _quadratic{};

        glm::vec3 _ambient{};
        glm::vec3 _diffuse{};
        glm::vec3 _specular{};
    };
}    //namespace Tools::Lights

#endif    //INC_2_SHADERS_POINTLIGHT_HPP
