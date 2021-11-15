//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Button.h"
#include "Orbit.h"
#include "Handler.h"

#define LIST(arg) static std::vector<arg*> list##arg;
#define LISTING(arg) new predrawer(&list##arg)
#define LIST_INIT(arg) std::vector<arg*> Containers::list##arg(0);


struct Containers {
private:
    struct drawer {
        virtual void drawe() = 0;
        virtual void handle() = 0;
        virtual ~drawer() = default;
    };

    template<typename T>
    struct predrawer : public drawer {
    protected:
        std::vector<T>* m_ptr;
    public:
        explicit predrawer(std::vector<T>* ptr) : m_ptr(ptr)
        {
        }
        ~predrawer() override = default;
        void drawe() final
        {
            drawAll(*m_ptr);
        }
        void handle() final
        {
            handleAll(*m_ptr);
        }
    };

    static std::vector<drawer*> base;

public:
    friend drawer;

    LIST(Button)
    LIST(Orbit)

    template<typename T>
    static void erase(std::vector<T>& a_vector, const T& a_member)
    {
        auto it = std::find(a_vector.begin(), a_vector.end(), a_member);
        if(it == a_vector.end())
            throw std::invalid_argument("Containers::erase : invalid member to delete - could not find");
        a_vector.erase(it);
    }

    static void drawAll();

    template<typename T>
    static void drawAll(std::vector<T>& a_vector)
    {
        for (auto& x : a_vector){
            x->draw(Handler::window());
        }
    }

    template<typename C>
    static void drawIf(C comparator)
    {
        for (auto& x : base){
            if(comparator(x))
                x->drawe();
        }
    }

    template<typename T, typename C>
    void drawIf(std::vector<T>& a_vector, C comparator)
    {
        for (auto& x : a_vector) {
            if (comparator(x))
                x->draw(Handler::window());
        }
    }

    static void handleAll();

    template<typename T>
    static void handleAll(std::vector<T>& a_vector)
    {
        for (auto& x : a_vector){
            x->handle();
        }
    }

    Containers() = delete;
};