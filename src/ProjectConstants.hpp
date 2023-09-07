//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_PROJECTCONSTANTS_HPP
#define INC_2_SHADERS_PROJECTCONSTANTS_HPP

#include <iostream>
#include <fstream>
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
}

#endif    //INC_2_SHADERS_PROJECTCONSTANTS_HPP
