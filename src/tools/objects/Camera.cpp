//
// Created by VerOchka on 07.09.2023.
//

#include "Camera.hpp"

namespace Objects {
    Camera::Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up) : _position(position), _up(up), _front(target) {
        // процесс Грамма-Шмидта
        _reverse_direction = glm::normalize(position - target);
        _right_direction = glm::normalize(glm::cross(glm::normalize(up), _reverse_direction));
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

    void Camera::lookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up) {
        auto z_axis = glm::normalize(eye - center);
        auto x_axis = glm::normalize(glm::cross(glm::normalize(up), z_axis));
        auto y_axis = glm::cross(z_axis, x_axis);

        glm::mat4 translation(1.0f);
        translation[3][0] = -_position.x;
        translation[3][1]= -_position.y;
        translation[3][2] = -_position.z;

        glm::mat4 rotation(1.0f);
        rotation[0][0] = x_axis.x;
        rotation[1][0] = x_axis.y;
        rotation[2][0] = x_axis.z;

        rotation[0][1] = y_axis.x;
        rotation[1][1] = y_axis.y;
        rotation[2][1] = y_axis.z;

        rotation[0][2] = z_axis.x;
        rotation[1][2] = z_axis.y;
        rotation[2][2] = z_axis.z;

        _view = rotation * translation;
    }
}
