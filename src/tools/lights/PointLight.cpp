//
// Created by VerOchka on 25.09.2023.
//

#include "PointLight.hpp"

namespace Tools::Lights {
    void PointLight::serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) {
        shader_program->use();

        auto name = "pointLight" + std::to_string(id);

        shader_program->set3FloatVector(name + ".ambient", _ambient);
        shader_program->set3FloatVector(name + ".diffuse", _diffuse);
        shader_program->set3FloatVector(name + ".specular", _specular);
        shader_program->set3FloatVector(name + ".position", _position);

        shader_program->setFloat(name + ".constant", 1.0f);
        shader_program->setFloat(name + ".linear", 0.09f);
        shader_program->setFloat(name + ".quadratic", 0.032f);
    }

    void PointLight::setPosition(const glm::vec3& position) {
        _position = position;
    }

    void PointLight::setConstant(float constant) {
        _constant = constant;
    }

    void PointLight::setLinear(float linear) {
        _linear = linear;
    }

    void PointLight::setQuadratic(float quadratic) {
        _quadratic = quadratic;
    }

    void PointLight::setAmbient(const glm::vec3& ambient) {
        _ambient = ambient;
    }

    void PointLight::setDiffuse(const glm::vec3& diffuse) {
        _diffuse = diffuse;
    }

    void PointLight::setSpecular(const glm::vec3& specular) {
        _specular = specular;
    }

}    //namespace Tools::Lights
