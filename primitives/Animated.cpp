#include "Animated.h"
#include "../core/Handler.h"


Animated::Animated(const std::string &a_string, frames a_frames, pixels a_x, pixels a_y) :
    Entry( a_string ),
    m_animation(a_string, m_sprite, a_x, a_y, a_frames)
{
    m_sprite.scale(Handler::gHandler->x_ratio, Handler::gHandler->y_ratio);
}

Animated::Animated(const std::string& a_string, frames a_frames, pixels a_pixels) :
    Entry( a_string ),
    m_animation(a_string, m_sprite, a_pixels, a_pixels, a_frames)
{
    m_sprite.scale(Handler::gHandler->x_ratio, Handler::gHandler->x_ratio);
}

void Animated::handle()
{
    m_animation.play( m_animation_speed * Handler::gHandler->alpha(), m_animation_direction );
}

