//
// Created by VerOchka on 10.09.2023.
//

#include "Shaders.hpp"

namespace Constants {
    std::map<Shaders::Sources, std::string> Shaders::files = {
        {Shaders::Sources::INVERTED_VERT, "inverted.vert"},
        {Shaders::Sources::THIRDD_UNIF_TEXTURE_VERT, "thirdd_uniform_texture.vert"},
        {Shaders::Sources::COLOR_VERT, "color_shader.vert"},
        {Shaders::Sources::TEXTURE_VERT, "texture_shader.vert"},
        {Shaders::Sources::UNIF_FRAG, "uniform_shader.frag"},
        {Shaders::Sources::COLOR_FRAG, "color_shader.frag"},
        {Shaders::Sources::TEXTURE_FRAG, "texture_shader.frag"},
        {Shaders::Sources::SIMPLE_VERT, "shader.vert"},
        {Shaders::Sources::SIMPLE_FRAG, "shader.frag"},
        {Shaders::Sources::THIRDD_UNIF_VERT, "thirdd_uniform.vert"},
        {Shaders::Sources::THIRDD_LIGHT_FRAG, "thirdd_light.frag"},
        {Shaders::Sources::STATIC_LIGHT_FRAG, "static_light.frag"},
        {Shaders::Sources::THIRDD_LIGHT_MAT_FRAG, "thirdd_uniform_material.frag"},
        {Shaders::Sources::THIRDD_LIGHT_TEXT_FRAG, "thirdd_light_texture.frag"},
        {Shaders::Sources::THIRDD_LIGHT_TEXT_VERT, "thirdd_light_texture.vert"},
        {Shaders::Sources::THIRDD_LIGHT_DIR_TEXT_FRAG, "thirdd_dir_light_text.frag"},
        {Shaders::Sources::SEARCHLIGHT_FRAG, "searchlight_text.frag"},
        {Shaders::Sources::COMBINED_LIGHT_FRAG, "combined_light_tex.frag"}
    };

    std::string Shaders::shaders_path = ProgramData::getValue<std::string>("shaders");

    [[maybe_unused]] std::string Shaders::getPath(Shaders::Sources name) {
        using namespace ProgramData;

        auto s = project_path + separator + shaders_path + separator + files[name];
        std::cout << s << std::endl;
        return s;
    }
}
