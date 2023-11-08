//
// Created by VerOchka on 02.10.2023.
//

#ifndef INC_2_SHADERS_PROGRAM10_HPP
#define INC_2_SHADERS_PROGRAM10_HPP

#include <vector>

#include "Program.hpp"
#include "../tools/Drawer.hpp"
#include "../tools/objects/faces/Cube.hpp"
#include "../tools/objects/textures/Loader.hpp"

class Program10 : public Program {
public:
    Program10();
    void run() override;

private:
    void configureShaders();
    void configureTextures();
    void configureObjects();

    std::shared_ptr<Tools::Shaders::ShaderProgram> _skybox_shader;

    std::shared_ptr<Tools::Drawer> _cube_drawer{};

    Tools::Objects::Textures::Texture::Ptr _skybox_texture;
};

#endif    //INC_2_SHADERS_PROGRAM10_HPP
