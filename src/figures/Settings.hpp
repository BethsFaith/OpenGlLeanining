//
// Created by VerOchka on 16.08.2023.
//

#ifndef INC_2_SHADERS_SETTINGS_HPP
#define INC_2_SHADERS_SETTINGS_HPP

namespace Figures {
    struct Settings {
        const unsigned int& bind_flag;
        bool with_texture = false;
        bool with_color = false;
        int dimension = 2;
    };
}

#endif    //INC_2_SHADERS_SETTINGS_HPP
