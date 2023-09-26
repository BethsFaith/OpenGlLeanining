//
// Created by VerOchka on 14.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM6_HPP
#define INC_2_SHADERS_PROGRAM6_HPP

#include "../tools/CameraController.hpp"
#include "../tools/objects/faces/Cube.hpp"
#include "../tools/objects/faces/Rectangle.hpp"
#include "../tools/objects/libHeadears/glm.hpp"
#include "../tools/objects/textures/Loader.hpp"
#include "Program.hpp"

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
    std::shared_ptr<Tools::Shaders::ShaderProgram> _lighting_shader_program;
    std::shared_ptr<Tools::Shaders::ShaderProgram> _light_source_shader_program;

    std::shared_ptr<Tools::Objects::Camera> _camera;
    std::shared_ptr<Tools::CameraController> _camera_controller;

    Tools::Drawer _drawer{};

    Tools::Objects::Textures::TextureLoader _texture1{GL_TEXTURE0};
    Tools::Objects::Textures::TextureLoader _texture2{GL_TEXTURE1};
};


#endif    //INC_2_SHADERS_PROGRAM6_HPP
