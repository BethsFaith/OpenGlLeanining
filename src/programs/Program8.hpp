//
// Created by VerOchka on 21.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM8_HPP
#define INC_2_SHADERS_PROGRAM8_HPP

#include "../constants/Models.hpp"
#include "../tools/CameraController.hpp"
#include "../tools/lights/DirectionalLight.hpp"
#include "../tools/lights/SpotLight.hpp"
#include "../tools/objects/Model.hpp"
#include "Program.hpp"

class Program8 : public Program {
public:
    Program8();
    ~Program8() override = default;

    void run() override;

private:
    void configureShaders();

    std::shared_ptr<Tools::Objects::Model> _model;

    std::shared_ptr<Tools::Shaders::ShaderProgram> _shader_program;

    Tools::Lights::DirectionalLight _dirLight{};
    Tools::Lights::SpotLight _spot_light{};
};

#endif    //INC_2_SHADERS_PROGRAM8_HPP
