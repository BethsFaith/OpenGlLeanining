//
// Created by VerOchka on 25.09.2023.
//

#ifndef INC_2_SHADERS_DIRECTIONALLIGHT_HPP
#define INC_2_SHADERS_DIRECTIONALLIGHT_HPP

#include "../objects/libHeadears/glm.hpp"
#include "SerializableLight.hpp"

namespace Tools::Lights {
    class DirectionalLight : public SerializableLight {
    public:
        DirectionalLight() = default;
        ~DirectionalLight() override = default;

        void serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) override;

        void setDirection(const glm::vec3& direction);
        void setAmbient(const glm::vec3& ambient);
        void setDiffuse(const glm::vec3& diffuse);
        void setSpecular(const glm::vec3& specular);

    private:
        glm::vec3 _direction{};
        glm::vec3 _ambient{};
        glm::vec3 _diffuse{};
        glm::vec3 _specular{};
    };
}    //namespace Tools::Lights

#endif    //INC_2_SHADERS_DIRECTIONALLIGHT_HPP
