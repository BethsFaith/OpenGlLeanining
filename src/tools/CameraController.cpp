//
// Created by VerOchka on 07.09.2023.
//

#include "CameraController.hpp"

#include <utility>

namespace Tools {
    CameraController::CameraController(std::shared_ptr<Objects::Camera> camera, const float& camera_speed) : _camera(std::move(camera)), _camera_speed(camera_speed) {}

    CameraController::CameraController(std::shared_ptr<Objects::Camera> camera) : CameraController(std::move(camera), 0.05f){}

    void CameraController::setCamera(const std::shared_ptr<Objects::Camera>& camera) {
        _camera = camera;
    }

    void CameraController::setCameraSpeed(float camera_speed) {
        _camera_speed = camera_speed;
    }

    void CameraController::forward() {
        auto camera_pos = _camera->getPosition();

        camera_pos += getSpeed() * _camera->getFront();

        _camera->setPosition(camera_pos);
    }

    void CameraController::right() {
        auto camera_pos = _camera->getPosition();

        camera_pos += glm::normalize(glm::cross(_camera->getFront(), _camera->getUp())) * getSpeed();

        _camera->setPosition(camera_pos);
    }

    void CameraController::left() {
        auto camera_pos = _camera->getPosition();

        camera_pos -= glm::normalize(glm::cross(_camera->getFront(), _camera->getUp())) * getSpeed();

        _camera->setPosition(camera_pos);
    }

    void CameraController::back() {
        auto camera_pos = _camera->getPosition();

        camera_pos -= getSpeed() * _camera->getFront();

        _camera->setPosition(camera_pos);
    }

    void CameraController::updateDeltaTime() {
        auto currentFrame = (float)glfwGetTime();

        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

    float CameraController::getSpeed(){
        return _camera_speed * deltaTime;
    }
}    //namespace Tools
