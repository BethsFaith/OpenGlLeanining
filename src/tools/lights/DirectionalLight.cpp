//
// Created by VerOchka on 25.09.2023.
//

#include "DirectionalLight.hpp"

namespace Tools::Lights {

    void DirectionalLight::serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) {
        shader_program->use();

        auto name = "dirLight" + std::to_string(id);

        shader_program->set3FloatVector(name + ".direction", _direction);
        shader_program->set3FloatVector(name + ".ambient", _ambient);
        shader_program->set3FloatVector(name + ".diffuse", _diffuse);
        shader_program->set3FloatVector(name + ".specular", _specular);
    }

    void DirectionalLight::setDirection(const glm::vec3& direction) {
        _direction = direction;
    }

    void DirectionalLight::setAmbient(const glm::vec3& ambient) {
        _ambient = ambient;
    }

    void DirectionalLight::setDiffuse(const glm::vec3& diffuse) {
        _diffuse = diffuse;
    }

    void DirectionalLight::setSpecular(const glm::vec3& specular) {
        _specular = specular;
    }
}    //namespace Tools::Lights
