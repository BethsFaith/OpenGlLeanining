//
// Created by VerOchka on 17.08.2023.
//

#ifndef INC_2_SHADERS_PROGRAM2_HPP
#define INC_2_SHADERS_PROGRAM2_HPP

#include <filesystem>

#include "../tools/objects/faces/Rectangle.hpp"
#include "../tools/objects/libHeadears/glm.hpp"
#include "../tools/objects/textures/Loader.hpp"
#include "Program.hpp"

// Устаревшее, не использовать без переписывания!!!
class Program2 : public Program {
public:
    Program2();
    ~Program2() override = default;

    void run() override;

    void processKeyboardInput(GLFWwindow* window) override;
    void processMouseInput(double x_pos, double y_pos) override;
    void processMouseScroll(double x_offset, double y_offset) override;
    void setDeltaTime(const float& delta_time) override;

private:
    void setMixValue(float x);
    void setTransform(glm::mat4 trans);

    std::shared_ptr<Tools::Shaders::ShaderProgram> _shader_program;
    Tools::Drawer _drawer{};
    Tools::Objects::Textures::TextureLoader _texture1{GL_TEXTURE0};
    Tools::Objects::Textures::TextureLoader _texture2{GL_TEXTURE1};

    float _mix_value = 0.2;
};

#endif    //INC_2_SHADERS_PROGRAM2_HPP
