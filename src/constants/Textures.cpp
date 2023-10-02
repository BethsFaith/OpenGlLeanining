//
// Created by VerOchka on 10.09.2023.
//

#include "Textures.hpp"

namespace Constants {
    std::map<Textures::Sources, std::string> Textures::paths = {
        {Textures::Sources::FACE, "awesomeface.png"},
        {Textures::Sources::CONTAINER, "container.jpg"},
        {Textures::Sources::CONTAINER_2, "container_2.png"},
        {Textures::Sources::CONTAINER_2_SPECULAR, "container_2_specular.png"},
        {Textures::Sources::CONTAINER_2_SPECULAR_RAINBOW, "container_2_specular_2.png"},
        {Textures::Sources::EMISSION, "emission.jpg"},
        {Textures::Sources::MARBLE, "marble.jpg"},
        {Textures::Sources::METAL, "metal.jpg"}
    };

    std::string Textures::textures_path = ProgramData::getValue<std::string>("textures");

    std::string Textures::getPath(Textures::Sources name) {
        using namespace ProgramData;

        auto s = project_path + separator + textures_path + separator + paths[name];
        std::cout << s << std::endl;
        return s;
    }
}    //namespace Constants
