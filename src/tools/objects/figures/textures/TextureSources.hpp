//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_TEXTURESOURCES_HPP
#define INC_2_SHADERS_TEXTURESOURCES_HPP

#include "../../../../ProjectConstants.hpp"

namespace TextureSources {
    static std::string path = ProjectConstants::getProjectValue<std::string>("path");

    static std::string face_path = path+"/src/tools/objects/figures/textures/rsrc/awesomeface.png";

    static std::string container_path = path+"/src/tools/objects/figures/textures/rsrc/container.jpg";
}

#endif    //INC_2_SHADERS_TEXTURESOURCES_HPP
