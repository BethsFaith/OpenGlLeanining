//
// Created by VerOchka on 21.09.2023.
//

#include "Program8.hpp"

Program8::Program8() {
    configureShaders();

    using namespace Constants;

    auto model_paths = Models::getPath(Models::Sources::GUITAR_BACKPACK);

    _model = std::make_shared<Tools::Objects::Model>(model_paths.object);
}

void Program8::configureShaders() {
    using namespace Constants;

    _shader_program = std::make_shared<Tools::Shaders::ShaderProgram>(
        Shaders::getPath(Shaders::Sources::LOAD_MODULE_VERT),
        Shaders::getPath(Shaders::Sources::LOAD_MODULE_FRAG));

    // Рендеринг загруженной модели
    _shader_program->use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // смещаем вниз чтобы быть в центре сцены
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// объект слишком большой для нашей сцены, поэтому немного уменьшим его
    _shader_program->set4FloatMat("model", glm::value_ptr(model));

    // свойства материала
    _shader_program->setFloat("material.shininess", 32.0f);

     //свойства света
    glm::vec3 white_light_color = {1.0, 1.0, 1.0};
    _dirLight.setDirection({-0.2f, -1.0f, -0.3f});
    _dirLight.setAmbient({white_light_color * glm::vec3(0.1f)});
    _dirLight.setDiffuse({white_light_color * glm::vec3(0.2f)});
    _dirLight.setDiffuse({white_light_color * glm::vec3(0.2f)});

    _spot_light.setAmbient(white_light_color * glm::vec3(0.0f));
    _spot_light.setDiffuse(white_light_color * glm::vec3(1.0f));
    _spot_light.setSpecular(glm::vec3(1.0f));
    _spot_light.setConstant(1.0f);
    _spot_light.setLinear(0.09f);
    _spot_light.setQuadratic(0.032f);
    _spot_light.setCutOff(glm::cos(glm::radians(12.5f)));
    _spot_light.setOuterCutOff(glm::cos(glm::radians(14.0f)));
}

void Program8::run() {
    _shader_program->use();
    int width, height;
    ProgramData::pullDesktopResolution(width, height);

    glm::mat4 projection = glm::perspective(glm::radians(camera->getZoom()),
                                            (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = camera->getView();

    _shader_program->set4FloatMat("projection", glm::value_ptr(projection));
    _shader_program->set4FloatMat("view", glm::value_ptr(view));
    _shader_program->set3FloatVector("viewPos", camera->getPosition());

    _spot_light.setPosition(camera->getPosition());
    _spot_light.setDirection(camera->getFront());

    _spot_light.serialize(_shader_program, 1);
    _dirLight.serialize(_shader_program, 1);

    _model->draw(_shader_program);
}
