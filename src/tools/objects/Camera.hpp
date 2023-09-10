//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_CAMERA_HPP
#define INC_2_SHADERS_CAMERA_HPP

#include "libHeadears/glm.hpp"
#include "libHeadears/glfw.hpp"

namespace Objects {
    class Camera {
    public:
        Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up);
        ~Camera() = default;

        [[nodiscard]] const glm::mat4& getView() const;
        [[nodiscard]] const glm::vec3& getPosition() const;
        [[nodiscard]] const glm::vec3& getUp() const;
        [[nodiscard]] const glm::vec3& getFront() const;
        [[nodiscard]] const float& getZoom() const;

        void setPosition(const glm::vec3& position);
        void setUp(const glm::vec3& up);
        void setFront(const glm::vec3& front);
        void setZoom(float zoom);

    private:
        void lookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
        void updateView();

        glm::vec3 _position;
        glm::vec3 _up;
        glm::vec3 _front;

        glm::vec3 _reverse_direction{};
        glm::vec3 _up_direction{};
        glm::vec3 _right_direction{};

        glm::mat4 _view{};
        float _zoom = 45.0f;
    };
}    //namespace Tools

#endif    //INC_2_SHADERS_CAMERA_HPP
