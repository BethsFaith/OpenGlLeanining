//
// Created by VerOchka on 10.09.2023.
//

#ifndef INC_2_SHADERS_TEXTURES_HPP
#define INC_2_SHADERS_TEXTURES_HPP

#include "../ProgramData.hpp"

namespace Constants {
    class Textures {
    public:
        enum Sources {
            FACE,
            CONTAINER,
            CONTAINER_2,
            CONTAINER_2_SPECULAR,
            CONTAINER_2_SPECULAR_RAINBOW,
            EMISSION,
            MARBLE,
            METAL,
            SKYBOX
        };

        [[maybe_unused]] static std::string getPath(Sources name);
        static std::string getTexturesPath();
    private:
        static std::map<Sources, std::string> paths;
        static std::string textures_path;
    };
}    //namespace Constants

#endif    //INC_2_SHADERS_TEXTURES_HPP
