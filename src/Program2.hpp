//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM2_HPP
#define INC_2_SHADERS_PROGRAM2_HPP

#include <filesystem>

#include "lib_headears/glm.hpp"
#include "Program.hpp"
#include "figures/Rectangle.hpp"
#include "figures/textures/Texture.hpp"

class Program2 : Program{
public:
    Program2();
    ~Program2() override = default;

    void run() override;

    void processUserInput(GLFWwindow* window) override;
private:
    void setMixValue(float x);
    void setTransform(glm::mat4 trans);

    std::shared_ptr<ShaderProgram> _shader_program;
    Drawer _drawer{};
    Texture _texture1{GL_TEXTURE0};
    Texture _texture2{GL_TEXTURE1};

    float _mix_value = 0.2;
};

#endif    //INC_2_SHADERS_PROGRAM2_HPP
