//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Button.h"

#define LIST(arg) static std::vector<arg*> list##arg;
#define LIST_INIT(arg) std::vector<arg*> Containers::list##arg(0);


struct Containers {
    LIST(Button)
    template<typename T>
    static void erase(std::vector<T>& a_vector, const T& a_member)
    {
        auto it = std::find(a_vector.begin(), a_vector.end(), a_member);
        if(it == a_vector.end())
            throw std::invalid_argument("Containers::erase : invalid member to delete - could not find");
        a_vector.erase(it);
    }

    template<typename T>
    static void drawAll(std::vector<T>& a_vector)
    {
        for(auto& x : a_vector){
            x->draw(*Settings::g_window);
        }
    }

    template<typename T, typename C>
    void drawIf(std::vector<T>& a_vector, C comparator)
    {
        for(auto& x : a_vector){
            if(comparator(x))
                x->draw(*Settings::g_window);
        }
    }
};