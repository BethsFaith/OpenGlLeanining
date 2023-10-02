//
// Created by VerOchka on 16.09.2023.
//

#include "Program7.hpp"

glm::vec3 Program7::cube_positions[10] = {glm::vec3(0.0f, 0.0f, 0.0f),
                              glm::vec3(2.0f, 5.0f, -15.0f),
                              glm::vec3(-1.5f, -2.2f, -2.5f),
                              glm::vec3(-3.8f, -2.0f, -12.3f),
                              glm::vec3(2.4f, -0.4f, -3.5f),
                              glm::vec3(-1.7f, 3.0f, -7.5f),
                              glm::vec3(1.3f, -2.0f, -2.5f),
                              glm::vec3(1.5f, 2.0f, -2.5f),
                              glm::vec3(1.5f, 0.2f, -1.5f),
                              glm::vec3(-1.3f, 1.0f, -1.5f)};
glm::vec3 Program7::point_light_positions[4] = {glm::vec3(0.7f, 0.2f, 2.0f),
    glm::vec3(2.3f, -3.3f, -4.0f),
    glm::vec3(-4.0f, -2.0f, -12.0f),
    glm::vec3(0.0f, 0.0f, -3.0f),
};
glm::vec3 Program7::point_light_colors[4] = {
    {0.05, 0.0, 1.0},
    {0.05, 0.0, 1.0},
    {0.05, 0.0, 1.0},
    {0.05, 0.0, 1.0}
};

Program7::Program7() {
    using namespace Constants;

    _light_source_shader_program = std::make_shared<Tools::Shaders::ShaderProgram>
        (Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_TEXT_VERT),
         Shaders::getPath(Shaders::Sources::STATIC_LIGHT_FRAG));
    _lighting_shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Shaders::getPath(Shaders::Sources::THIRDD_LIGHT_TEXT_VERT),
        Shaders::getPath(Shaders::Sources::COMBINED_LIGHT_FRAG));

//    auto vbo = std::make_shared<Tools::Objects::Faces::Buffers::VBO>(coords);


    Tools::Objects::Faces::Settings settings = {.with_normals = true, .with_texture = true};
    auto cube = std::make_shared<Tools::Objects::Faces::Cube>(settings);

    settings = {.with_normals = false, .with_texture = false};
    auto light_cube = std::make_shared<Tools::Objects::Faces::Cube>(settings);

    light_cube->bindData(GL_STATIC_DRAW);
    cube->bindData(GL_STATIC_DRAW);

    _cube_drawer.addPrimitive(cube, _lighting_shader_program);
    _light_drawer.addPrimitive(light_cube, _light_source_shader_program);

    _texture1 = std::make_shared<Tools::Objects::Textures::Texture>
                ("",Textures::getPath(Textures::Sources::CONTAINER_2).c_str());
    _texture2 = std::make_shared<Tools::Objects::Textures::Texture>
        ("",Textures::getPath(Textures::Sources::CONTAINER_2_SPECULAR).c_str());

    std::vector<Tools::Objects::Textures::Loader::Param> params = {
        {.name = GL_TEXTURE_WRAP_S, .value =  GL_CLAMP_TO_EDGE},
        {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
        {.name = GL_TEXTURE_MIN_FILTER, .value =  GL_NEAREST},
        {.name = GL_TEXTURE_MAG_FILTER, .value =  GL_NEAREST}
    };

    Tools::Objects::Textures::Loader::load2d(*_texture1, params);
    Tools::Objects::Textures::Loader::load2d(*_texture2, params);

    int width, height;
    ProgramData::pullDesktopResolution(width, height);
    last_x = (float)width / 2;
    last_y = (float)height / 2;

    glm::vec3 white_light_color = {1.0, 1.0, 1.0};

    // свойства материала
    _lighting_shader_program->use();
    _lighting_shader_program->setInt("material.diffuse", 0);
    _lighting_shader_program->setInt("material.specular", 1);
    _lighting_shader_program->setFloat("material.shininess", 32.0f);

    // свойства света
    _lighting_shader_program->set3FloatVector("dirLight.direction",  -0.2f, -1.0f, -0.3f);
    _lighting_shader_program->set3FloatVector("dirLight.ambient", white_light_color * glm::vec3(0.1f));
    _lighting_shader_program->set3FloatVector("dirLight.diffuse", white_light_color * glm::vec3(0.2f));
    _lighting_shader_program->set3FloatVector("dirLight.specular", white_light_color * glm::vec3(0.2f));

    for (unsigned int i = 0; i < 4; ++i) {
        std::string elem_name = "pointLights[" + std::to_string(i) + "].";

        glm::vec3 ambient_color = point_light_colors[i] * glm::vec3(0.2f); // 0.2f
        glm::vec3 diffuse_color = point_light_colors[i] * glm::vec3(0.3f); // 0.5f
        glm::vec3 specular_color = point_light_colors[i] * glm::vec3(0.5f); // 0.5f

        _lighting_shader_program->set3FloatVector(elem_name + "ambient", ambient_color);
        _lighting_shader_program->set3FloatVector(elem_name + "diffuse", diffuse_color);
        _lighting_shader_program->set3FloatVector(elem_name + "specular", specular_color);
        _lighting_shader_program->set3FloatVector(elem_name + "position", point_light_positions[i]);

        _lighting_shader_program->setFloat(elem_name + "constant", 1.0f);
        _lighting_shader_program->setFloat(elem_name + "linear", 0.09f);
        _lighting_shader_program->setFloat(elem_name + "quadratic", 0.032f);
    }

    _lighting_shader_program->set3FloatVector("spotLight.ambient", white_light_color * glm::vec3(0.0f));
    _lighting_shader_program->set3FloatVector("spotLight.diffuse", white_light_color * glm::vec3(1.0f));
    _lighting_shader_program->set3FloatVector("spotLight.specular", glm::vec3(1.0f));
    _lighting_shader_program->setFloat("spotLight.constant", 1.0f);
    _lighting_shader_program->setFloat("spotLight.linear", 0.09f);
    _lighting_shader_program->setFloat("spotLight.quadratic", 0.032f);
    _lighting_shader_program->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    _lighting_shader_program->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(14.0f)));

    // свойства источника (точечного) света
    _light_source_shader_program->use();
    _light_source_shader_program->set3FloatVector("Color", white_light_color);

    cube->setDrawCallback([this]() {
        glm::vec3 light_pos(1.2f, 1.0f, 2.0f);

        int width, height;
        ProgramData::pullDesktopResolution(width, height);

        auto projection = glm::perspective(glm::radians(camera->getZoom()),
                                           (float)width / (float)height, 0.1f, 100.0f);
        // расположение объекта
        _lighting_shader_program->set4FloatMat("view", glm::value_ptr(camera->getView()));
        _lighting_shader_program->set4FloatMat("projection", glm::value_ptr(projection));
        _lighting_shader_program->set3FloatVector("viewPos", camera->getPosition());

        // свойства света
        _lighting_shader_program->set3FloatVector("spotLight.position",camera->getPosition());
        _lighting_shader_program->set3FloatVector("spotLight.direction",camera->getFront());
    });

    light_cube->setDrawCallback([this]() {
        // расположение источника (точечного) света
        glm::vec3 light_pos(1.2f, 1.0f, 2.0f);

        int width, height;
        ProgramData::pullDesktopResolution(width, height);

        auto projection = glm::perspective(glm::radians(camera->getZoom()),
                                           (float)width / (float)height, 0.1f, 100.0f);

        _light_source_shader_program->set4FloatMat("view", glm::value_ptr(camera->getView()));
        _light_source_shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    });
}

void Program7::run() {
    _texture1->activate(GL_TEXTURE0);
    _texture2->activate(GL_TEXTURE1);

    _lighting_shader_program->use();
    for (unsigned int i = 0; i < 10; ++i) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cube_positions[i]);
        float angle = 20.0f * float(i + 1);
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        _lighting_shader_program->set4FloatMat("model", glm::value_ptr(model));

        _cube_drawer.draw();
    }

    _light_source_shader_program->use();

    for (int i{}; i < 4; ++i) {

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, point_light_positions[i]);
        model = glm::scale(model, glm::vec3(0.2f)); // куб меньшего размера

        _light_source_shader_program->set4FloatMat("model", glm::value_ptr(model));
        _light_source_shader_program->set3FloatVector("Color", point_light_colors[i]);

        _light_drawer.draw();
    }
}

void Program7::updateView() {
}