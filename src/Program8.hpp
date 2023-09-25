//
// Created by VerOchka on 21.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM8_HPP
#define INC_2_SHADERS_PROGRAM8_HPP

#include "Program.hpp"
#include "constants/Models.hpp"
#include "tools/objects/Model.hpp"
#include "tools/CameraController.hpp"

class Program8 : public Program{
public:
    Program8();
    ~Program8() override = default;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;

    void setDeltaTime(const float& delta_time) override;

private:
    void configureShaders();
    void configureCamera();

    std::shared_ptr<Tools::Objects::Model> _model;

    std::shared_ptr<Tools::Shaders::ShaderProgram> _shader_program;

    std::shared_ptr<Tools::Objects::Camera> _camera;
    std::shared_ptr<Tools::CameraController> _camera_controller;
};

#endif    //INC_2_SHADERS_PROGRAM8_HPP
