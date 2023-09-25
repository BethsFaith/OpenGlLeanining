//
// Created by VerOchka on 25.09.2023.
//

#ifndef INC_2_SHADERS_SERIALIZABLELIGHT_HPP
#define INC_2_SHADERS_SERIALIZABLELIGHT_HPP

#include "../shaders/ShaderProgram.hpp"

namespace Tools::Lights {
    class SerializableLight {
    public:
        SerializableLight() = default;
        virtual ~SerializableLight() = default;

        virtual void serialize(const Shaders::ShaderProgram::Ptr& shader_program, const int& id) = 0;
    };
}    //namespace Tools::Lights

#endif    //INC_2_SHADERS_SERIALIZABLELIGHT_HPP
