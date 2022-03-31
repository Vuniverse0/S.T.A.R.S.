#pragma once

#include "../primitives/Entry.h"


struct Gui : Entry{
protected:
    using Entry::Entry;
    ~Gui() override = default;
};

struct Changer_I {virtual void call() = 0;};
template<typename T>
struct Changer : Lambda<T>, Changer_I {
    Changer(T lambd) : Lambda<T>{lambd}{}
    using Lambda<T>::operator();
    void call() override { operator()(); }
};
template<typename T> Changer(T) -> Changer<T>;


struct Changeble_I {virtual void call() = 0;};
template<typename T>
struct Changeable : Lambda<T>, Changeble_I {
    Changeable(T lambd) : Lambda<T>{lambd}{}
    using Lambda<T>::operator();
    void call() override { operator()( this ); }
};
template<typename T> Changeable(T) -> Changeable<T>;

template<typename ...Args>
struct Traceable {
protected:
    struct List_Funct_I{ List_Funct_I* m_next = nullptr; virtual void handle( Args... ) = 0; };
    template<typename T>
    struct List_Funct : List_Funct_I{
        void ( T:: * m_pointer ) ( Args... ) = nullptr;
        T* m_these = nullptr;
        List_Funct(T* these, void ( T:: * pointer ) ( Args... )): m_these(these), m_pointer(pointer){}
        void handle(Args... args) override { (m_these->*m_pointer)(args...); }
    };
    List_Funct_I* m_list = nullptr;
    void Insert( List_Funct_I& list )
    {
        if ( !m_list ) {
            m_list = &list;
        } else {
            List_Funct_I *tmp = m_list;
            while ( tmp->m_next )
                tmp = tmp->m_next;
            tmp->m_next = &list;
        }
    }
protected:
    sf::Sprite* m_p_sprite = nullptr;
    void handle(Args... args)
    {
        List_Funct_I* tmp = m_list;
        if ( tmp ) tmp->handle(args...);
        else return;
        while ( tmp -> m_next != nullptr ) {
            tmp->m_next->handle(args...);
            tmp = tmp->m_next;
        }
    }
};

struct Clickable : virtual Traceable<const sf::Event&>{
    void m_handle(const sf::Event& event);
    [[nodiscard]] bool isOnClick();
protected:
    Clickable();
private:
    bool m_mouse{false};
    List_Funct<Clickable> m_list{ this, &Clickable::m_handle };
};

struct Suggestive : virtual Traceable<const sf::Event&>{
    void m_handle(const sf::Event& event);
    [[nodiscard]] bool isMouseOn() const;
protected:
    Suggestive();
private:
    bool m_mouse{false};
    List_Funct<Suggestive> m_list{ this, &Suggestive::m_handle };
};

struct Shorten : virtual Traceable<>{
    void m_handle();
    void click();
protected:
    Shorten();
    sf::Vector2f m_normal_scale;
private:
    bool m_mouse{false};
    List_Funct<Shorten> m_list{ this, &Shorten::m_handle };
};