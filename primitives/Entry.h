#pragma once

#include "../utility/typedefs_and_globals.h"


class Entry {
protected:
    sf::Sprite m_sprite{};
    bool m_visibility{true};
    sf::Texture m_object_texture{};
public:
    Entry() = delete;
    explicit Entry(const std::string& a_string, float_t x_ratio = 1, float_t y_ratio = 1);
    Entry(const Entry& ent);
    virtual ~Entry() = default;

    virtual void move(float_t x, float_t y);
    void setPosition(float_t x, float_t y);
    sf::Rect<float> getGlobalBounds() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getScale() const;
    const sf::Vector2f& getOrigin() const;
    bool hide(), show();
    virtual void handle() = 0;
    virtual void handle(const sf::Event& event);
    virtual void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const;
};


