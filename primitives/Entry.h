#pragma once

#include "../utility/typedefs_and_globals.h"

class Entry {
protected:
    sf::Sprite m_sprite{};
    bool m_visibility{true};
    sf::Texture m_object_texture{};
    static sf::RenderWindow& defaultRenderWindow();
public:
    Entry() = delete;
    explicit Entry(const std::string& a_string, float_t x_ratio = 1, float_t y_ratio = 1);
    Entry(const Entry& ent);
    Entry(Entry&& ent) noexcept ;
    virtual ~Entry() = default;
    sf::Sprite& sprite();
    bool hide(), show();
    virtual void handle() = 0;
    virtual void handle(const sf::Event& event);
    virtual void draw(sf::RenderWindow& window = defaultRenderWindow());
};


