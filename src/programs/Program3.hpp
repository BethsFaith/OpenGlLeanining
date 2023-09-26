//
// Created by VerOchka on 26.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM3_HPP
#define INC_2_SHADERS_PROGRAM3_HPP

#include "../tools/objects/Camera.hpp"
#include "../tools/objects/faces/Cube.hpp"
#include "../tools/objects/faces/Rectangle.hpp"
#include "../tools/objects/libHeadears/glm.hpp"
#include "../tools/objects/textures/Loader.hpp"
#include "Program.hpp"

class Program3 : public Program{
public:
    Program3();
    ~Program3() override = default;

    void run() override;
    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;
    void setDeltaTime(const float& delta_time) override;

private:
    std::shared_ptr<Tools::Shaders::ShaderProgram> _shader_program;

    Tools::Drawer _drawer{};
    Tools::Objects::Textures::TextureLoader _texture1{GL_TEXTURE0};
    Tools::Objects::Textures::TextureLoader _texture2{GL_TEXTURE1};
};

#endif    //INC_2_SHADERS_PROGRAM3_HPP
