//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "../core/overloaded.h"


struct Containers {
    template<typename T>
    static void drawAll()
    {
        for (auto& x : T::m_all)
            x->draw();
    }

    template<typename T, typename C>
    static void drawIf(C comparator)
    {
        for (auto& x : T::m_all) {
            if (comparator(x))
                x->draw();
        }
    }

    template<typename T, typename ...Args>
    static void handleAll(Args... args)
    {
        for (auto& x : T::m_all)
            x->handle(args...);
    }

    template<typename T, typename ...Args>
    static void handle(Args... args)//for call static self passing
    {
        T::handle(args...);
    }

    template<typename ...Args>
    static void trait(Args... args)//for call static self passing
    {
        static overloaded m_overloaded{
            [](){}//no_callback
        };
        m_overloaded(args...);
    }

    template<typename T, typename C>
    static void applyAll(C functor)//no handle call, make it yourself in comparator
    {
        for (auto& x : T::m_all)
            functor(x);
    }
    Containers() = delete;
};