//
// Created by VerOchka on 21.09.2023.
//

#ifndef INC_2_SHADERS_MODELS_HPP
#define INC_2_SHADERS_MODELS_HPP

#include <iostream>
#include <map>

#include "../ProgramData.hpp"

namespace Constants {
    class Models {
    public:
        enum Sources {
            GUITAR_BACKPACK,
            AYA_WOMAN
        };
        struct ModelFiles {
            std::string directory;
            std::string object;
            std::string textures_directory;
        };

        [[maybe_unused]] static ModelFiles getPath(Sources name);
    private:
        static std::map<Sources, ModelFiles> files;
        static std::string models_path;
    };
}

#endif    //INC_2_SHADERS_MODELS_HPP
