//
// Created by VerOchka on 14.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM6_HPP
#define INC_2_SHADERS_PROGRAM6_HPP

#include "Program.hpp"
#include "tools/CameraController.hpp"
#include "tools/objects/figures/Cube.hpp"
#include "tools/objects/figures/textures/Texture.hpp"
#include "tools/objects/libHeadears/glm.hpp"

class Program6 : public Program {
public:
    Program6();
    ~Program6() override = default;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_pos, double y_pos) override;

    void setDeltaTime(const float& delta_time) override;

protected:
    void updateView();

private:
    std::shared_ptr<Figures::ShaderProgram> _lighting_shader_program;
    std::shared_ptr<Figures::ShaderProgram> _light_source_shader_program;

    std::shared_ptr<Objects::Camera> _camera;
    std::shared_ptr<Tools::CameraController> _camera_controller;

    Figures::Texture _texture1{GL_TEXTURE0};
    Figures::Texture _texture2{GL_TEXTURE1};

    Figures::Drawer _drawer{};
};


#endif    //INC_2_SHADERS_PROGRAM6_HPP
