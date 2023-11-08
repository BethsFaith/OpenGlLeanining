//
// Created by VerOchka on 21.09.2023.
//

#include "Models.hpp"

namespace Constants {
    std::map<Models::Sources, Models::ModelFiles> Models::files = {
        {Models::Sources::GUITAR_BACKPACK,
         {"backpack", "backpack.obj", "textures"}},
        {Models::Sources::AYA_WOMAN,
         {"aya", "scene.gltf", ""}},
        {Models::Sources::FLOWERS,
         {"Grass", "grass.obj", "Textyres"}}
//        {Models::Sources::FLOWERS,
//         {"Flowered", "OD-1898_1281.obj", "Textyres"}}
    };

    std::string Models::models_path = ProgramData::getValue<std::string>("models");

    Models::ModelFiles Models::getPath(Models::Sources name) {
        using namespace ProgramData;

        static auto path =   project_path + separator + models_path + separator;

        auto model_files = files[name];

        model_files.directory = path + model_files.directory;
        std::cout << model_files.directory << std::endl;
        model_files.object = model_files.directory + separator + model_files.object;
        std::cout << model_files.object << std::endl;
        model_files.textures_directory = model_files.directory + separator + model_files.textures_directory;
        std::cout << model_files.textures_directory << std::endl;

        return model_files;
    }
}
