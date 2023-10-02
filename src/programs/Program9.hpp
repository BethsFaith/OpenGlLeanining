//
// Created by VerOchka on 29.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAM9_HPP
#define INC_2_SHADERS_PROGRAM9_HPP

#include "Program.hpp"
#include "../tools/objects/faces/Cube.hpp"
#include "../tools/objects/faces/Plane.hpp"
#include "../tools/objects/textures/Loader.hpp"
#include "../tools/Drawer.hpp"

class Program9 : public Program {
public:
    Program9();
    ~Program9() override = default;

    void run() override;

private:
    void configureShaders();

    std::shared_ptr<Tools::Shaders::ShaderProgram> _shader_program;

    std::shared_ptr<Tools::Drawer> _cube_drawer{};
    std::shared_ptr<Tools::Drawer> _floor_drawer{};

    Tools::Objects::Textures::Texture::Ptr _cube_texture;
    Tools::Objects::Textures::Texture::Ptr _floor_texture;
};

#endif    //INC_2_SHADERS_PROGRAM9_HPP
