//
// Created by VerOchka on 29.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM_HPP
#define INC_2_SHADERS_PROGRAM_HPP

#include "../tools/CameraController.hpp"
#include "AbstractProgram.hpp"

class Program : public AbstractProgram {
public:
    Program();
    ~Program() override = default;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;
    void setDeltaTime(const float& delta_time) override;

protected:
    std::shared_ptr<Tools::Objects::Camera> camera;
    std::shared_ptr<Tools::CameraController> camera_controller;
};

#endif    //INC_2_SHADERS_PROGRAM_HPP
