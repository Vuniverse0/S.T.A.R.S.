#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Entry.h"
#include "Directions.h"
#include "../primitives/Group.h"


class Place {
    Place() = default;
public:
    template<Orientation O, int N>
    static void group(const sf::Vector2f& v, const float_t& separator, Group<N>& args)//[x, c] =  v | [c, y] =  v
    {
        float_t sum_a;
        if constexpr(O == Vertical){
            for ( auto arg : args )
                sum_a += ( ( arg->sprite().getGlobalBounds().height + separator ) );
            sum_a /= 2;
            for ( auto arg : args ) {
                auto& tmp = arg->sprite();
                tmp.setPosition(
                        v.x,
                        v.y - sum_a + (
                                tmp.getScale().y * tmp.getOrigin().y
                        )
                        + separator / 2
                );
                sum_a -= (tmp.getGlobalBounds().height + separator);
            }
        } else if constexpr (O == Horizontal){
            for ( auto arg : args )
                sum_a += ( ( arg->sprite().getGlobalBounds().width + separator ) );
            sum_a /= 2;
            for ( auto arg : args ) {
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
        }
    }

    template<Orientation O, typename ...Args>
    static void group(const sf::Vector2f& v, const float_t& separator, Args& ...args)//[x, c] =  v | [c, y] =  v
    {
        float_t sum_a;
        if constexpr(O == Vertical){
            sum_a = ((args.sprite().getGlobalBounds().height + separator) + ... ) / 2.f;
            ( [&](auto& ent) {
                ent.sprite().setPosition(
                        v.x,
                        v.y - sum_a + (
                                args.sprite().getScale().y * args.sprite().getOrigin().y
                        )
                        + separator / 2
                );
                sum_a -= ( args.sprite().getGlobalBounds().height + separator );
            }(args),...);
        } else if constexpr (O == Horizontal){
            sum_a = ((args.sprite().getGlobalBounds().width + separator) + ... ) / 2.f;
            ( [&](auto& ent) {
                ent.sprite().setPosition(
                        v.x - sum_a + (
                                args.sprite().getScale().x * args.sprite().getOrigin().x
                        )
                        + separator / 2,
                        v.y
                );
                sum_a -= ( args.sprite().getGlobalBounds().width + separator );
            }(args),...);
        }
    }
};