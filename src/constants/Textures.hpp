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
            CONTAINER
        };

        [[maybe_unused]] static std::string getPath(Sources name);
    private:
        static std::map<Sources, std::string> paths;
        static std::string textures_path;
    };
}    //namespace Constants

#endif    //INC_2_SHADERS_TEXTURES_HPP
