#pragma once

#include "../utility/typedefs_and_globals.h"

class Entry {
protected:
    sf::Sprite m_sprite{};
    bool m_visibility{true};
    sf::Texture m_object_texture{};
    virtual ~Entry() = default;
public:
    Entry() = delete;
    sf::Sprite& sprite();
    explicit Entry(const std::string& a_string, float_t x_ratio = 1, float_t y_ratio = 1);
    bool hide(), show();
    virtual void handle() = 0;
    virtual void handle(const sf::Event& event);
    void draw() const;
};


