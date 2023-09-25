//
// Created by VerOchka on 16.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM7_HPP
#define INC_2_SHADERS_PROGRAM7_HPP

#include "Program.hpp"
#include "tools/CameraController.hpp"
#include "tools/objects/faces/Cube.hpp"
#include "tools/objects/faces/Rectangle.hpp"
#include "tools/objects/libHeadears/glm.hpp"
#include "tools/objects/textures/Loader.hpp"

#define DIRECTIONAL_LIGHT 0
#define POSITIONAL_LIGHT 1

class Program7 : public Program {
public:
    Program7();
    ~Program7() override = default;

    void run() override;
    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;
    void setDeltaTime(const float& delta_time) override;

protected:
    void updateView();

private:
    static glm::vec3 cube_positions[10];
    static glm::vec3 point_light_positions[4];
    static glm::vec3 point_light_colors[4];

    std::shared_ptr<Tools::Shaders::ShaderProgram> _lighting_shader_program;
    std::shared_ptr<Tools::Shaders::ShaderProgram> _light_source_shader_program;

    std::shared_ptr<Tools::Objects::Camera> _camera;
    std::shared_ptr<Tools::CameraController> _camera_controller;

    Tools::Objects::Textures::TextureLoader _texture1{GL_TEXTURE0};
    Tools::Objects::Textures::TextureLoader _texture2{GL_TEXTURE1};

    Tools::Drawer _cube_drawer{};
    Tools::Drawer _light_drawer{};
};

#endif    //INC_2_SHADERS_PROGRAM7_HPP
