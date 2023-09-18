//
// Created by VerOchka on 08.08.2023.
//

#ifndef CREATING_WINDOW_SHADERSOURCES_HPP
#define CREATING_WINDOW_SHADERSOURCES_HPP

#include "../ProgramData.hpp"

namespace Constants {
    class Shaders {
    public:
        enum Sources {
            INVERTED_VERT,
            TEXTURE_VERT,
            TEXTURE_FRAG,
            THIRDD_UNIF_TEXTURE_VERT,
            THIRDD_UNIF_VERT,
            THIRDD_LIGHT_FRAG,
            THIRDD_LIGHT_MAT_FRAG,
            THIRDD_LIGHT_TEXT_VERT,
            THIRDD_LIGHT_TEXT_FRAG,
            THIRDD_LIGHT_DIR_TEXT_FRAG,
            UNIF_FRAG,
            COLOR_VERT,
            COLOR_FRAG,
            SIMPLE_VERT,
            SIMPLE_FRAG,
            STATIC_LIGHT_FRAG,
            SEARCHLIGHT_FRAG,
            COMBINED_LIGHT_FRAG
        };

        [[maybe_unused]] static std::string getPath(Sources name);
    private:
        static std::map<Sources, std::string> files;
        static std::string shaders_path;
    };
}    //namespace Constants

#endif    //CREATING_WINDOW_SHADERSOURCES_HPP
