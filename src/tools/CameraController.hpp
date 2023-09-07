//
// Created by VerOchka on 07.09.2023.
//

#ifndef INC_2_SHADERS_CAMERACONTROLLER_HPP
#define INC_2_SHADERS_CAMERACONTROLLER_HPP

#include <memory>

#include "objects/Camera.hpp"

namespace Tools {
    class CameraController {
    public:
        CameraController(std::shared_ptr<Objects::Camera> camera, const float& camera_speed);
        explicit CameraController(std::shared_ptr<Objects::Camera> camera);

        void forward();
        void right();
        void left();
        void back();

        void setCamera(const std::shared_ptr<Objects::Camera>& camera);
        void setCameraSpeed(float camera_speed);
        void setDeltaTime(float delta_time);

    protected:
        [[nodiscard]] float getSpeed() const;

        float deltaTime = 0.0f;
    private:
        std::shared_ptr<Objects::Camera> _camera;

        float _camera_speed;
    };
}

#endif    //INC_2_SHADERS_CAMERACONTROLLER_HPP
