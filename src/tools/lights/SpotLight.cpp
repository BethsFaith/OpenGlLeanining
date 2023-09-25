//
// Created by VerOchka on 25.09.2023.
//

#include "SpotLight.hpp"

namespace Tools::Lights {
    void SpotLight::serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) {
        shader_program->use();

        auto name = "spotLight" + std::to_string(id);

        shader_program->set3FloatVector(name + ".ambient", _ambient);
        shader_program->set3FloatVector(name + ".diffuse", _diffuse);
        shader_program->set3FloatVector(name + ".specular", _specular);
        shader_program->setFloat(name + ".constant", _constant);
        shader_program->setFloat(name + ".linear", _linear);
        shader_program->setFloat(name + ".quadratic", _quadratic);
        shader_program->setFloat(name + ".cutOff", _cutOff);
        shader_program->setFloat(name + ".outerCutOff", _outerCutOff);

        shader_program->set3FloatVector(name + ".position", _position);
        shader_program->set3FloatVector(name + ".direction", _direction);
    }

    void SpotLight::setPosition(const glm::vec3& position) {
        _position = position;
    }

    void SpotLight::setDirection(const glm::vec3& direction) {
        _direction = direction;
    }

    void SpotLight::setCutOff(float cut_off) {
        _cutOff = cut_off;
    }

    void SpotLight::setOuterCutOff(float outer_cut_off) {
        _outerCutOff = outer_cut_off;
    }

    void SpotLight::setConstant(float constant) {
        _constant = constant;
    }

    void SpotLight::setLinear(float linear) {
        _linear = linear;
    }

    void SpotLight::setQuadratic(float quadratic) {
        _quadratic = quadratic;
    }

    void SpotLight::setAmbient(const glm::vec3& ambient) {
        _ambient = ambient;
    }

    void SpotLight::setDiffuse(const glm::vec3& diffuse) {
        _diffuse = diffuse;
    }

    void SpotLight::setSpecular(const glm::vec3& specular) {
        _specular = specular;
    }
}    //namespace Tools::Lights
