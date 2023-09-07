//
// Created by VerOchka on 08.08.2023.
//

#ifndef CREATING_WINDOW_SHADERSOURCES_HPP
#define CREATING_WINDOW_SHADERSOURCES_HPP

#include "../../ProjectConstants.hpp"

namespace Figures::ShaderSources {
    static std::string path = ProjectConstants::getProjectValue<std::string>("path");

    static const std::string vertex_shader_source = path+"/src/figures/shaders/rsrc/shader.vert";

    static const std::string thirdd_vertex_shader_source = path+"/src/figures/shaders/rsrc/thirdd_uniform_shader.vert";

    static const std::string color_vertex_shader_source = path+"/src/figures/shaders/rsrc/color_shader.vert";

    static const std::string inverted_vertex_shader_source = path+"/src/figures/shaders/rsrc/inverted.vert";

    static const std::string texture_vertex_shader_source = path+"/src/figures/shaders/rsrc/texture_shader.vert";

    static const std::string fragment_shader_source = path+"/src/figures/shaders/rsrc/shader.frag";

    static const std::string uniform_fragment_shader_source = path+"/src/figures/shaders/rsrc/uniform_shader.frag";

    static const std::string color_fragment_shader_source = path+"/src/figures/shaders/rsrc/color_shader.frag";

    static const std::string texture_fragment_shader_source = path+"/src/figures/shaders/rsrc/texture_shader.frag";
}

#endif    //CREATING_WINDOW_SHADERSOURCES_HPP
