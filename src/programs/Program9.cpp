//
// Created by VerOchka on 29.09.2023.
//

#include "Program9.hpp"

Program9::Program9() {
    configureShaders();

    using namespace Tools::Objects;
    auto cube = std::make_shared<Faces::Cube>
        (Faces::Settings{.with_normals = false, .with_tangent = false, .with_bitangent = false});
    auto plane = std::make_shared<Tools::Objects::Faces::Plane>
        (Faces::Settings{.with_texture = true});

    cube->bindData(GL_STATIC_DRAW);
    plane->bindData(GL_STATIC_DRAW);

    _cube_drawer = std::make_shared<Tools::Drawer>();
    _floor_drawer = std::make_shared<Tools::Drawer>();
    _cube_drawer->addPrimitive(cube, _shader_program);
    _floor_drawer->addPrimitive(plane, _shader_program);

    _cube_texture = std::make_shared<Textures::Texture>("",
                                                    Constants::Textures::getPath(Constants::Textures::MARBLE));
    _floor_texture = std::make_shared<Textures::Texture>("",
                                                    Constants::Textures::getPath(Constants::Textures::METAL));

    std::vector<Textures::Loader::Param> params = {
        {.name = GL_TEXTURE_WRAP_S, .value =  GL_REPEAT},
        {.name = GL_TEXTURE_WRAP_T, .value = GL_REPEAT},
        {.name = GL_TEXTURE_MIN_FILTER, .value =  GL_LINEAR_MIPMAP_LINEAR},
        {.name = GL_TEXTURE_MAG_FILTER, .value =  GL_LINEAR}
    };

    Textures::Loader::load2d(*_cube_texture, params);
    Textures::Loader::load2d(*_floor_texture, params);
}

void Program9::configureShaders() {
    using namespace Constants;

    _shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Shaders::getPath(Shaders::Sources::THIRDD_UNIF_TEXTURE_VERT),
        Shaders::getPath(Shaders::Sources::TEXTURE_FRAG));
}

void Program9::run() {
    _shader_program->use();

    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    glm::mat4 projection = glm::perspective(glm::radians(camera->getZoom()),
                                            (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = camera->getView();
    glm::mat4 model = glm::mat4(1.0f);

    _shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    _shader_program->set4FloatMat("view", glm::value_ptr(view));

    // пол
    _floor_texture->activate(GL_TEXTURE0);

    _shader_program->set4FloatMat("model", glm::value_ptr(model));
    _floor_drawer->draw();

    _floor_texture->deactivate();

    // кубы
    _cube_texture->activate(GL_TEXTURE0);

    model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
    _shader_program->set4FloatMat("model", glm::value_ptr(model));
    _cube_drawer->draw();

    model = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f));
    _shader_program->set4FloatMat("model", glm::value_ptr(model));
    _cube_drawer->draw();

    _cube_texture->deactivate();
}