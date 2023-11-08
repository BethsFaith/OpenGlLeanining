//
// Created by VerOchka on 02.10.2023.
//

#include "Program10.hpp"

Program10::Program10() {
    configureShaders();
    configureObjects();
    configureTextures();
}

void Program10::configureShaders() {
    auto path = Constants::Shaders::getShadersPath() + ProgramData::separator;
    _skybox_shader = std::make_shared<Tools::Shaders::ShaderProgram>(path + "sampler_cube.vert",
                                                                      path + "sampler_cube.frag");
}

void Program10::configureObjects() {
    using namespace Tools::Objects;
    auto cube = std::make_shared<Faces::Cube>(Faces::Settings{
        .with_normals = false,
        .with_texture_coords = false,
        .with_tangent = false,
        .with_bitangent = false,
    });

    cube->bindData(GL_STATIC_DRAW);

    _cube_drawer = std::make_shared<Tools::Drawer>();
    _cube_drawer->addPrimitive(cube, _skybox_shader);
}

void Program10::configureTextures() {
    using namespace Tools::Objects;
    auto path = Constants::Textures::getTexturesPath() + ProgramData::separator + "skybox" + ProgramData::separator;
    std::vector<std::string> faces = {"right.jpg", "left.jpg", "top.jpg", "bottom.jpg", "front.jpg", "back.jpg"};

    _skybox_texture = std::make_shared<Textures::Texture>("skybox", path,
                                                          GL_TEXTURE_CUBE_MAP);

    Textures::Loader::loadCubeMap2d(*_skybox_texture, faces, {
                                                   {.name = GL_TEXTURE_MIN_FILTER, .value = GL_LINEAR},
                                                   {.name = GL_TEXTURE_MAG_FILTER, .value = GL_LINEAR},
                                                   {.name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE},
                                                   {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
                                                   {.name = GL_TEXTURE_WRAP_R, .value = GL_CLAMP_TO_EDGE},
                                               });

    _skybox_shader->use();
    _skybox_shader->setInt("cube_map", 0);
}

void Program10::run() {
    glDepthMask(GL_FALSE);
    glDepthFunc(GL_LEQUAL);

    _skybox_shader->use();
    _skybox_texture->activate(GL_TEXTURE0);

    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    glm::mat4 projection = glm::perspective(glm::radians(camera->getZoom()),
                                            (float)width / (float)height, 0.1f, 100.0f);
    //glm::mat4 view = glm::mat4(glm::mat3(camera->getView()));
    glm::mat4 view = camera->getView();

    _skybox_shader->set4FloatMat("projection", glm::value_ptr(projection));
    _skybox_shader->set4FloatMat("view", glm::value_ptr(view));

    _cube_drawer->draw();

    glDepthMask(GL_TRUE);

    _skybox_texture->deactivate();

    // отрисовка остальной части сцены
}
