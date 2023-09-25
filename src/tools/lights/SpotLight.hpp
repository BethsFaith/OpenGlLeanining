//
// Created by VerOchka on 25.09.2023.
//

#ifndef INC_2_SHADERS_SPOTLIGHT_HPP
#define INC_2_SHADERS_SPOTLIGHT_HPP

#include "../objects/libHeadears/glm.hpp"
#include "SerializableLight.hpp"

namespace Tools::Lights {
    class SpotLight : public SerializableLight {
    public:
        SpotLight() = default;
        ~SpotLight() override = default;

        void serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) override;

        void setPosition(const glm::vec3& position);
        void setDirection(const glm::vec3& direction);
        void setCutOff(float cut_off);
        void setOuterCutOff(float outer_cut_off);
        void setConstant(float constant);
        void setLinear(float linear);
        void setQuadratic(float quadratic);
        void setAmbient(const glm::vec3& ambient);
        void setDiffuse(const glm::vec3& diffuse);
        void setSpecular(const glm::vec3& specular);

    private:
        glm::vec3 _position{};
        glm::vec3 _direction{};

        float _cutOff{};
        float _outerCutOff{};

        float _constant{};
        float _linear{};
        float _quadratic{};

        glm::vec3 _ambient{};
        glm::vec3 _diffuse{};
        glm::vec3 _specular{};
    };

}    // namespace Tools::Lights

#endif    //INC_2_SHADERS_SPOTLIGHT_HPP
