//
// Created by VerOchka on 26.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM3_HPP
#define INC_2_SHADERS_PROGRAM3_HPP

#include "Program.hpp"
#include "tools/objects/figures/Cube.hpp"
#include "tools/objects/figures/Rectangle.hpp"
#include "tools/objects/figures/textures/Texture.hpp"
#include "tools/objects/figures/textures/TextureSources.hpp"
#include "tools/objects/libHeadears/glm.hpp"
#include "tools/objects/Camera.hpp"

class Program3 : public Program{
public:
    Program3();
    ~Program3() override = default;

    void run() override;
    void processKeyboardInput(GLFWwindow* window) override;

private:
    std::shared_ptr<Figures::ShaderProgram> _shader_program;

    Figures::Drawer _drawer{};
    Figures::Texture _texture1{GL_TEXTURE0};
    Figures::Texture _texture2{GL_TEXTURE1};
};

#endif    //INC_2_SHADERS_PROGRAM3_HPP
