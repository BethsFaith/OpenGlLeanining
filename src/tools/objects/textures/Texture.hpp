//
// Created by VerOchka on 22.09.2023.
//

#ifndef INC_2_SHADERS_TEXTURE_HPP
#define INC_2_SHADERS_TEXTURE_HPP

#include "../libHeadears/glfw.hpp"

#include <iostream>

namespace Tools::Objects::Textures {
    class Texture {
    public:
        using Ptr = std::shared_ptr<Texture>;

        explicit Texture(std::string name, std::string path, GLenum type = GL_TEXTURE_2D);
        ~Texture();

        void activate(unsigned int gl_int) const;
        void deactivate() const;

        [[nodiscard]] unsigned int getId() const;
        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] const std::string& getPath() const;
        [[nodiscard]] GLenum getType() const;

    private:
        unsigned int _id{};
        std::string _name;
        std::string _path;
        GLenum _type;
    };
}    //namespace Tools::Objects::Textures

#endif    //INC_2_SHADERS_TEXTURE_HPP
