//
// Created by VerOchka on 07.09.2023.
//

#include "CameraController.hpp"

#include <utility>

namespace Tools {
    CameraController::CameraController(std::shared_ptr<Objects::Camera> camera, const float& camera_speed) : _camera(std::move(camera)), _camera_speed(camera_speed) {}

    CameraController::CameraController(std::shared_ptr<Objects::Camera> camera) : CameraController(std::move(camera), 0.05f){}

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

    float CameraController::getSpeed() const{
        return _camera_speed * deltaTime;
    }

    void CameraController::rotate(float x_offset, float y_offset) {
        yaw(x_offset);
        pitch(y_offset);
        rotate();
    }

    void CameraController::yaw(float offset) {
        _yaw += offset;
    }

    void CameraController::pitch(float offset) {
        _pitch += offset;

        if (_pitch > 89.0f)
            _pitch = 89.0f;
        if (_pitch < -89.0f)
            _pitch = -89.0f;
    }

    void CameraController::rotate() {
        glm::vec3 direction;
        direction.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
        direction.y = sin(glm::radians(_pitch));
        direction.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));

        _camera->setFront(glm::normalize(direction));
    }

    void CameraController::zoom(float y_offset) {
        auto zoom = _camera->getZoom();

        if (zoom >= 1.0f && zoom <= 45.0f) {
            zoom -= y_offset;
        }
        if (zoom <= 1.0f) {
            zoom = 1.0f;
        }
        if (zoom >= 45.0f) {
            zoom = 45.0f;
        }

        _camera->setZoom(zoom);
    }

    void CameraController::setCamera(const std::shared_ptr<Objects::Camera>& camera) {
        _camera = camera;
    }

    void CameraController::setCameraSpeed(float camera_speed) {
        _camera_speed = camera_speed;
    }

    void CameraController::setDeltaTime(float delta_time) {
        deltaTime = delta_time;
    }
}    //namespace Tools
