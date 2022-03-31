#include "Panel.h"



float_t Panel::separator;

void Panel::set_separator(const decltype(Panel::separator) &inp) { separator = inp; }

float_t Panel::calc(vertical_t, Entry* ent){return (ent->sprite().getGlobalBounds().height + separator);}
float_t Panel::calc(horizontal_t, Entry* ent){return (ent->sprite().getGlobalBounds().width + separator);}

void Panel::placeY(Entry *ent, float_t c, float_t y, float_t &sum_a)
{
    float_t x = c - sum_a;
    ent->sprite().setPosition(x + (ent->sprite().getScale().x * ent->sprite().getOrigin().x) + separator / 2 , y);
    sum_a -= (ent->sprite().getGlobalBounds().width + separator);
}

void Panel::placeX(Entry* ent, float_t c, float_t x, float_t& sum_a)
{
    float_t y = c - sum_a;
    ent->sprite().setPosition(x , y + (ent->sprite().getScale().y * ent->sprite().getOrigin().y) + separator / 2);
    sum_a -= (ent->sprite().getGlobalBounds().height + separator);
}
