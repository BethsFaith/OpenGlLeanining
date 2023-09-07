//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_PROJECTCONSTANTS_HPP
#define INC_2_SHADERS_PROJECTCONSTANTS_HPP

#include <iostream>
#include <fstream>
#include <wtypes.h>
#include <json/json.h>

namespace ProjectConstants {
    template<typename T>
    static T getProjectValue(const std::string& name) {
        std::ifstream ifstream("../../config.json", std::ifstream::binary);

        if (!ifstream.is_open()) {
            throw Json::Exception("File can't be open");
        }

        Json::Reader reader;
        Json::Value obj;
        reader.parse(ifstream, obj); // reader can also read strings

        ifstream.close();

        return obj[name].as<T>();
    }

    static void pullDesktopResolution(int& horizontal, int& vertical)
    {
        RECT desktop;
        // Get a handle to the desktop window
        const HWND hDesktop = GetDesktopWindow();
        // Get the size of screen to the variable desktop
        GetWindowRect(hDesktop, &desktop);
        // The top left corner will have coordinates (0,0)
        // and the bottom right corner will have coordinates
        // (horizontal, vertical)
        horizontal = desktop.right;
        vertical = desktop.bottom;
    }
}

#endif    //INC_2_SHADERS_PROJECTCONSTANTS_HPP
