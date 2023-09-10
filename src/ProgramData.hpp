//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_PROGRAMDATA_HPP
#define INC_2_SHADERS_PROGRAMDATA_HPP

#include <iostream>
#include <fstream>
#include <wtypes.h>
#include <json/json.h>

namespace ProgramData {
    template<typename T>
    static T getValue(const std::string& name) {
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

        const HWND hDesktop = GetDesktopWindow();

        GetWindowRect(hDesktop, &desktop);

        horizontal = desktop.right;
        vertical = desktop.bottom;
    }

    static std::string path = getValue<std::string>("path");

    static char separator = '/';
}

#endif    //INC_2_SHADERS_PROGRAMDATA_HPP
