//
// Created by VerOchka on 08.08.2023.
//

#ifndef CREATING_WINDOW_SHADERSOURCES_HPP
#define CREATING_WINDOW_SHADERSOURCES_HPP

#include "../../ProjectConstants.hpp"

namespace ShaderSources {
    static std::string path = ProjectConstants::getProjectValue<std::string>("path");

    static const std::string vertex_shader_source = path+"/src/figures/shaders/src/shader.vert";

    static const std::string thirdd_vertex_shader_source = path+"/src/figures/shaders/src/thirdd_uniform_shader.vert";

    static const std::string color_vertex_shader_source = path+"/src/figures/shaders/src/color_shader.vert";

    static const std::string inverted_vertex_shader_source = path+"/src/figures/shaders/src/inverted.vert";

    static const std::string texture_vertex_shader_source = path+"/src/figures/shaders/src/texture_shader.vert";

    static const std::string fragment_shader_source = path+"/src/figures/shaders/src/shader.frag";

    static const std::string uniform_fragment_shader_source = path+"/src/figures/shaders/src/uniform_shader.frag";

    static const std::string color_fragment_shader_source = path+"/src/figures/shaders/src/color_shader.frag";

    static const std::string texture_fragment_shader_source = path+"/src/figures/shaders/src/texture_shader.frag";
}

#endif    //CREATING_WINDOW_SHADERSOURCES_HPP
