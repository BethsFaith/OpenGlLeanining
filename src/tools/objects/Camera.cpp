//
// Created by VerOchka on 07.09.2023.
//

#include "Camera.hpp"

namespace Objects {
    Camera::Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up) : _position(position), _up(up), _front(target) {
        // процесс Грамма-Шмидта
        _reverse_direction = glm::normalize(position - target);
        _right_direction = glm::normalize(glm::cross(up, _reverse_direction));
        _up_direction = glm::cross(_reverse_direction, _right_direction);

        // создание матрицы вида
        updateView();
    }

    const glm::mat4& Camera::getView() const {
        return _view;
    }

    const glm::vec3& Camera::getPosition() const {
        return _position;
    }

    const glm::vec3& Camera::getUp() const {
        return _up;
    }

    const glm::vec3& Camera::getFront() const {
        return _front;
    }

    const float& Camera::getZoom() const {
        return _zoom;
    }

    void Camera::setPosition(const glm::vec3& position) {
        _position = position;
        updateView();
    }

    void Camera::setUp(const glm::vec3& up) {
        _up = up;
        updateView();
    }

    void Camera::setFront(const glm::vec3& front) {
        _front = front;
        updateView();
    }

    void Camera::setZoom(float zoom) {
        _zoom = zoom;
    }

    void Camera::updateView() {
        _view = glm::lookAt(_position, _position+_front, _up);
    }
}
