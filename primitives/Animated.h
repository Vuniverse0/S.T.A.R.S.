#pragma once

#include "Animation.h"
#include "Entry.h"


class Animated : public Entry {
protected:
    float_t m_animation_speed{0.f};
    bool m_animation_direction{true};
    Animation m_animation;
    Animated(const std::string& a_string, frames a_frames, pixels size_x, pixels size_y);
    Animated(const std::string& a_string, frames a_frames, pixels a_pixels);
    void handle() override;
    ~Animated() override = default;
};