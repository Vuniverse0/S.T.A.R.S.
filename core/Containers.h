//
// Created by vuniverse on 11/3/21.
//

#pragma once


struct Containers {
    template<typename T>
    static void drawAll()
    {
        for(auto& x : T::m_all)
            x->draw();
    }

    template<typename T>
    static void handleAll()
    {
        for(auto& x : T::m_all)
            x->handle();
    }

    Containers() = delete;
};