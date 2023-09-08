//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM4_HPP
#define INC_2_SHADERS_PROGRAM4_HPP

#include "Program.hpp"
#include "tools/objects/figures/Cube.hpp"
#include "tools/objects/figures/Rectangle.hpp"
#include "tools/objects/figures/textures/Texture.hpp"
#include "tools/objects/figures/textures/TextureSources.hpp"
#include "tools/objects/libHeadears/glm.hpp"
#include "tools/CameraController.hpp"

class Program4 : public Program {
public:
    Program4();
    ~Program4() override = default;

    void run() override;
    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;
    void setDeltaTime(const float& delta_time) override;

protected:
    void updateView();

private:
    std::shared_ptr<Figures::ShaderProgram> _shader_program;

    Figures::Drawer _drawer{};
    Figures::Texture _texture1{GL_TEXTURE0};
    Figures::Texture _texture2{GL_TEXTURE1};

    std::shared_ptr<Objects::Camera> _camera;
    std::shared_ptr<Tools::CameraController> _camera_controller;
};

#endif    //INC_2_SHADERS_PROGRAM4_HPP
