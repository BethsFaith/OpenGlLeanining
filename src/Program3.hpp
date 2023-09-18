//
// Created by VerOchka on 26.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM3_HPP
#define INC_2_SHADERS_PROGRAM3_HPP

#include "Program.hpp"
#include "tools/objects/Camera.hpp"
#include "tools/objects/faces/Cube.hpp"
#include "tools/objects/faces/Rectangle.hpp"
#include "tools/objects/textures/TextureWorker.hpp"
#include "tools/objects/libHeadears/glm.hpp"

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
    Tools::Objects::Textures::TextureWorker _texture1{GL_TEXTURE0};
    Tools::Objects::Textures::TextureWorker _texture2{GL_TEXTURE1};
};

#endif    //INC_2_SHADERS_PROGRAM3_HPP
