//
// Created by VerOchka on 16.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM7_HPP
#define INC_2_SHADERS_PROGRAM7_HPP

#include "../tools/CameraController.hpp"
#include "../tools/objects/faces/Cube.hpp"
#include "../tools/objects/faces/Rectangle.hpp"
#include "../tools/objects/libHeadears/glm.hpp"
#include "../tools/objects/textures/Loader.hpp"
#include "Program.hpp"

#define DIRECTIONAL_LIGHT 0
#define POSITIONAL_LIGHT 1

class Program7 : public Program {
public:
    Program7();
    ~Program7() override = default;

    void run() override;

protected:
    void updateView();

private:
    static glm::vec3 cube_positions[10];
    static glm::vec3 point_light_positions[4];
    static glm::vec3 point_light_colors[4];

    std::shared_ptr<Tools::Shaders::ShaderProgram> _lighting_shader_program;
    std::shared_ptr<Tools::Shaders::ShaderProgram> _light_source_shader_program;

    Tools::Objects::Textures::Texture::Ptr _texture1;
    Tools::Objects::Textures::Texture::Ptr _texture2;

    Tools::Drawer _cube_drawer{};
    Tools::Drawer _light_drawer{};
};

#endif    //INC_2_SHADERS_PROGRAM7_HPP
