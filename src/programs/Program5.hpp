//
// Created by VerOchka on 10.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM5_HPP
#define INC_2_SHADERS_PROGRAM5_HPP

#include "../tools/CameraController.hpp"
#include "../tools/objects/faces/Cube.hpp"
#include "../tools/objects/faces/Rectangle.hpp"
#include "../tools/objects/libHeadears/glm.hpp"
#include "../tools/objects/textures/Loader.hpp"
#include "Program.hpp"

class Program5 : public Program {
public:
    Program5();
    ~Program5() override = default;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_pos, double y_pos) override;

    void setDeltaTime(const float& delta_time) override;

protected:
    void updateView();

private:
    std::shared_ptr<Tools::Shaders::ShaderProgram> _lighting_shader_program;
    std::shared_ptr<Tools::Shaders::ShaderProgram> _light_source_shader_program;

    std::shared_ptr<Tools::Objects::Camera> _camera;
    std::shared_ptr<Tools::CameraController> _camera_controller;

    Tools::Drawer _drawer{};
};

#endif    //INC_2_SHADERS_PROGRAM5_HPP
