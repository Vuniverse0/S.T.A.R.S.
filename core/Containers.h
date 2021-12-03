//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../interface/Interfaces.h"
#include "../objects/Objects.h"
#include "Handler.h"


struct Containers {
private:
    struct drawer {
        virtual ~drawer() = default;
        virtual void drawe() = 0;
        virtual void handle() = 0;
        virtual void erase(Entry*) = 0;
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
            for (auto& x : (*m_ptr)) {
                x->draw(Handler::window());
            }
        }
        void handle() final
        {
            for (auto& x : (*m_ptr)) {
                x->handle();
            }
        }
        void erase(Entry* a_member) final
        {
            a_member = reinterpret_cast<T>(a_member);
            auto it = std::find(m_ptr->begin(), m_ptr->end(), a_member);
            if (it != m_ptr->end())
                m_ptr->erase(it);
        }
    };

    static std::vector<drawer*> m_handle_base;
    static std::vector<drawer*> m_drawe_base;

    constexpr static auto m_drawe_basePush{
            [](auto& vector)->char
            {
                m_drawe_base.push_back(new predrawer(&vector));
                return char();
            }
    };
    constexpr static auto m_handle_basePush{
            [](auto& vector)->char
            {
                m_handle_base.push_back(new predrawer(&vector));
                return char();
            }
    };
public:
    friend drawer;

    template<typename T>
    static void erase(const T& a_member) {
        for (auto &base : m_handle_base) {
            for( auto &x :m_handle_base )
                x->erase(a_member);
        }
        for (auto &base : m_drawe_base) {
            for( auto &x :m_drawe_base )
                x->erase(a_member);
        }
    }

    static void drawAll();

    template<typename T>
    static void drawTrait(T* drawable)
    {
        static std::vector<T*> vector;
        static auto _ = m_drawe_basePush(vector);
        vector.push_back(drawable);
    }

    static void handleAll();

    template<typename T>
    static void handleTrait(T* handlable)
    {
        static std::vector<T*> vector;
        static auto _ = m_handle_basePush(vector);
        vector.push_back(handlable);
    }

    Containers() = delete;
};