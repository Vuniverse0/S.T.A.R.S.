//
// Created by vuniverse on 11/3/21.
//

#pragma once


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

    template<typename T>
    static void handleAll()
    {
        for (auto& x : T::m_all)
            x->handle();
    }

    template<typename T, typename C>
    static void handleAll(C comparator)//no handle call, make it yourself in comparator
    {
        for (auto& x : T::m_all)
            comparator(x);
    }
    Containers() = delete;
};