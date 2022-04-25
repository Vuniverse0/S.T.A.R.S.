#include "Gui.h"


bool Clickable::isOnClick()
{
    if ( m_mouse ) m_mouse = false;
    else return false;
    return true;
}

void Clickable::m_handle(Event event)
{
    if (sf::Event::MouseButtonReleased == event.type)
        m_mouse = size_regulator(m_p_sprite).contains(event.mouseButton.x, event.mouseButton.y);
}

Clickable::Clickable() { Insert(m_list); }


void Suggestive::m_handle(Event event) {
    if ( sf::Event::MouseMoved == event.type )
        m_mouse = size_regulator(m_p_sprite).contains(event.mouseMove.x, event.mouseMove.y);
}

bool Suggestive::isMouseOn() const { return m_mouse; }

Suggestive::Suggestive() { Insert(m_list); }


void Shorten::m_handle()
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

Shorten::Shorten() { Insert(m_list); }


void Unfold::handle()
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
    int isVertical = m_direction == Up || m_direction == Down ? 1 : 0;
    int isRightDown = m_direction == Right || m_direction == Down ? 1 : 0;
    auto ort = isVertical ? &sf::Vector2<float>::y : &sf::Vector2<float>::x;
    auto ort2 = isVertical ? &sf::Rect<float>::height : &sf::Rect<float>::width;
    if( isMouseOn() ) {
        for (auto& beg : m_group) {
            auto &tmp = beg->sprite();
            if ( cmp[isRightDown]
                (
                    tmp.getPosition().*ort,
                    op[isRightDown]
                    (
                    m_p_sprite->getPosition().*ort,
                    sum + (tmp.getScale().*ort * tmp.getOrigin().*ort) + m_separator/2
                    )
                )
            )
                tmp.move(x, y);
            sum -= (tmp.getGlobalBounds().*ort2 + m_separator);
        }
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

void Unfold::handle( Event event ) { Traceable<Event>::handle( event ); }

Unfold::Unfold(Direction direction, Entry& base, Group_I &a_group, float_t separator) :
    m_group{a_group},
    m_direction{direction},
    sum_a{0},
    m_separator{separator}
{
    Traceable<Event>::m_p_sprite = & base.sprite();
    auto ort = direction == Up || direction == Down ? &sf::Rect<float>::height : &sf::Rect<float>::width;
    for ( auto arg : m_group )
        sum_a += ( ( arg->sprite().getGlobalBounds().*ort + m_separator ) );
}
