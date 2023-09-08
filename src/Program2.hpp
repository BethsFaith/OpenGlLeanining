//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM2_HPP
#define INC_2_SHADERS_PROGRAM2_HPP

#include <filesystem>

#include "tools/objects/libHeadears/glm.hpp"
#include "Program.hpp"
#include "tools/objects/figures/Rectangle.hpp"
#include "tools/objects/figures/textures/Texture.hpp"

class Program2 : public Program{
public:
    Program2();
    ~Program2() override = default;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
private:
    void setMixValue(float x);
    void setTransform(glm::mat4 trans);

    std::shared_ptr<Figures::ShaderProgram> _shader_program;
    Figures::Drawer _drawer{};
    Figures::Texture _texture1{GL_TEXTURE0};
    Figures::Texture _texture2{GL_TEXTURE1};

    float _mix_value = 0.2;
};

#endif    //INC_2_SHADERS_PROGRAM2_HPP
