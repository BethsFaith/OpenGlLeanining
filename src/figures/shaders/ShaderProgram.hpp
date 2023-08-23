//
// Created by VerOchka on 14.08.2023.
//

#ifndef INC_2_SHADERS_SHADERPROGRAM_HPP
#define INC_2_SHADERS_SHADERPROGRAM_HPP

#include "../../lib_headears/glfw.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderProgram {
public:
    // Конструктор считывает данные и выполняет построение шейдера
    ShaderProgram(const char* vertexPath, const char* fragmentPath);

    // Использование/активация шейдера
    void use();

    // Полезные uniform-функции
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void set4FloatVector(const std::string& name, float c1, float c2, float c3, float c4) const;
    void set4FloatMat(const std::string& name, const GLfloat *value) const;

    // ID - идентификатор программы
    unsigned int ID;
};


#endif    //INC_2_SHADERS_SHADERPROGRAM_HPP
