#pragma once

#include "Directions.h"
#include "../primitives/Group.h"


namespace Place{
    template<Orientation O, typename T>
    static void group(const sf::Vector2f& v, const float_t& separator, IGroup<T>& args)//[x, c] =  v | [c, y] =  v
    {
        float_t sum_a{};
        if constexpr(O == Vertical){
            for ( auto& item : args )
                sum_a += ((item->getGlobalBounds().height + separator));
            sum_a /= 2.f;
            for ( auto& item : args ) {
                item->setPosition(
                        v.x,
                        v.y - sum_a + (
                                item->getScale().y * item->getOrigin().y
                        )
                        + separator / 2.f
                );
                sum_a -= (item->getGlobalBounds().height + separator);
            }
        } else if constexpr (O == Horizontal){
            for ( auto& item : args )
                sum_a += ( ( item->getGlobalBounds().width + separator ) );
            sum_a /= 2;
            for ( auto& item : args ) {
                item->setPosition(
                        v.x - sum_a + (
                                item->getScale().x * item->getOrigin().x
                        )
                        + separator / 2,
                        v.y
                );
                sum_a -= (item->getGlobalBounds().height + separator);
            }
        }
    }

    template<Orientation O, typename ...Args, std::enable_if_t<
            ( sizeof...( Args ) > 1 ),
            bool
    > = true>
    static void group(const sf::Vector2f& v, const float_t& separator, Args& ...args)//[x, c] =  v | [c, y] =  v
    {
        float_t sum_a{};
        if constexpr(O == Vertical){
            sum_a = ((args.getGlobalBounds().height + separator) + ... ) / 2.f;
            ( [&](auto& ent) {
                ent.setPosition(
                        v.x,
                        v.y - sum_a + (
                                args.getScale().y * args.getOrigin().y
                        )
                        + separator / 2
                );
                sum_a -= ( args.getGlobalBounds().height + separator );
            }(args),...);
        } else if constexpr (O == Horizontal){
            sum_a = ((args.getGlobalBounds().width + separator) + ... ) / 2.f;
            ( [&](auto& ent) {
                ent.setPosition(
                        v.x - sum_a + (
                                args.getScale().x * args.getOrigin().x
                        )
                        + separator / 2,
                        v.y
                );
                sum_a -= ( args.getGlobalBounds().width + separator );
            }(args),...);
        }
    }
};