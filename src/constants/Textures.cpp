//
// Created by VerOchka on 10.09.2023.
//

#include "Textures.hpp"

namespace Constants {
    std::map<Textures::Sources, std::string> Textures::paths = {{Textures::Sources::FACE, "awesomeface.png"},
                                                      {Textures::Sources::CONTAINER, "container.jpg"}};

    std::string Textures::textures_path = ProgramData::getValue<std::string>("textures");

    std::string Textures::getPath(Textures::Sources name) {
        using namespace ProgramData;

        auto s = path + separator + textures_path + separator + paths[name];
        std::cout << s << std::endl;
        return s;
    }
}    //namespace Constants
