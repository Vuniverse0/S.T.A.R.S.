#include "Gui.h"


Clickable::Clickable(sf::Sprite* a_p_sprite)
        :m_p_sprite{a_p_sprite}
{}

bool Clickable::isOnClick()
{
    if ( m_mouse ) m_mouse = false;
    else return false;
    return true;
}

void Clickable::handle(const sf::Event& event)
{
    if (sf::Event::MouseButtonReleased == event.type)
        m_mouse = size_regulator(m_p_sprite).contains(event.mouseButton.x, event.mouseButton.y);
}




Suggestive::Suggestive(sf::Sprite* a_p_sprite)
        :m_p_sprite{a_p_sprite}
{}

void Suggestive::handle(const sf::Event& event) {
    if ( sf::Event::MouseMoved == event.type )
        m_mouse = size_regulator(m_p_sprite).contains(event.mouseMove.x, event.mouseMove.y);
}

bool Suggestive::isMouseOn() const { return m_mouse; }




Shorten::Shorten(sf::Vector2f a_normal_scale, sf::Sprite* a_p_sprite)
        :m_normal_scale{a_normal_scale}
        ,m_p_sprite{a_p_sprite}
{}

void Shorten::handle()
{
    if ( m_mouse ) {
        if ( m_p_sprite->getScale().x > m_normal_scale.x) {
            scale_by_mouse( m_p_sprite, false );
            scale_by_mouse( m_p_sprite, false );
        } else {
            m_mouse = false;
        }
    }
}

void Shorten::click(){ m_mouse = true; }




Activable::Activable(sf::Sprite *a_p_sprite)
    :m_p_sprite{a_p_sprite}
{}

void Activable::enable()
{
    m_active = true;
    sf::Uint8 light = 255; // 255 = initial brightness, 0 = black
    m_p_sprite->setColor(sf::Color(light, light, light));
}

void Activable::disable()
{
    m_active = false;
    sf::Uint8 light = 0 + 255 / 2; // 255 = initial brightness, 0 = black
    m_p_sprite->setColor(sf::Color(light, light, light));
}

bool Activable::is_active() const {return m_active;}




bool Unfold::handle(bool fold)
{
    float_t x{}, y{}, sum = sum_a;
    switch (m_direction){
        case None: break;
        case Up: y -= 10.f; break;
        case Down: y += 10.f; break;
        case Left: x -= 10.f; break;
        case Right: x += 10.f; break;
        default: assert(false);//No viable direction in Unfold
    }
    bool(*cmp [2])(float_t, float_t)=
    {
        +[](float_t f, float_t s){ return f > s; }
        ,+[](float_t f, float_t s){ return f < s; }
    };
    float_t(*op [2])(float_t, float_t)=
    {
            +[](float_t f, float_t s){ return f + s; }
            ,+[](float_t f, float_t s){ return f - s; }
    };
    int isVertical = ( m_direction == Up || m_direction == Down ? 1 : 0 );
    int isRightDown = ( m_direction == Right || m_direction == Down ? 1 : 0 );
    auto ort = isVertical ? &sf::Vector2<float>::y : &sf::Vector2<float>::x;
    auto ort2 = isVertical ? &sf::Rect<float>::height : &sf::Rect<float>::width;
    //TODO if fold
    for (auto item : m_group) {
        if ( cmp[isRightDown]
            (
                    item->getPosition().*ort,
                    op[isRightDown]
                (
                m_p_sprite->getPosition().*ort,
                sum + (item->getScale().*ort * item->getOrigin().*ort) + m_separator / 2
                )
            )
        )
            item->move(x, y);
        sum -= (item->getGlobalBounds().*ort2 + m_separator);
    }
#if 0
    for ( auto& arg : args )
        sum_a += ( ( arg->sprite().getGlobalBounds().width + separator ) );
    sum_a /= 2;
    for ( auto& arg : args ) {
        auto& tmp = arg->sprite();
        tmp.setPosition(
                v.x - sum_a + (
                        tmp.getScale().x * tmp.getOrigin().x
                )
                + separator / 2,
                v.y
        );
        sum_a -= (tmp.getGlobalBounds().height + separator);
    }
#endif
}


Unfold::Unfold(Direction direction, sf::Sprite* a_p_sprite, Group_I &a_group, float_t separator)
:m_group{a_group}
,m_direction{direction}
,sum_a{0}
,m_separator{separator}
,m_p_sprite{a_p_sprite}
{
    auto ort = direction == Up || direction == Down ? &sf::Rect<float>::height : &sf::Rect<float>::width;
    for ( auto arg : m_group )
        sum_a += ( ( arg->getGlobalBounds().*ort + m_separator ) );
}

bool Unfold::unfold(){return handle(false);}

bool Unfold::fold(){return handle(true);}