#pragma once

#include "Entry.h"

namespace iterator{
    template<typename N, typename M = N*>
    struct group_iterator{
        using curent = group_iterator<N, M>;
        explicit group_iterator(M pointer) : m_pointer{ pointer } {}
        N& operator*(){ return *static_cast<N*>(m_pointer); }
        const N& operator*() const{ return *static_cast<N*>(m_pointer); }
        curent operator++(int){ return ++m_pointer; };
        curent& operator++(){ m_pointer++; return *this; };
        curent operator--(int){ return --m_pointer; };
        curent& operator--(){ m_pointer--; return *this; };
        curent& operator+(int n){ m_pointer+= n; return *this; };
        curent& operator-(int n){ m_pointer-= n; return *this; };
        template<typename T>
        bool operator==(group_iterator<T, M> a){ return m_pointer == a.m_pointer; };
        template<typename T>
        bool operator!=(group_iterator<T, M> a){ return !(*this == a);};
    private:
        M m_pointer;
    };
}

template<typename T, typename IT = iterator::group_iterator<T*>>
struct IGroup{
    IT begin(){ return m_begin; };
    IT end(){ return m_end; };
    template<typename F>
    IGroup<T>& operator | (F functor)
    {
        for (auto tmp : *this)
            functor(tmp);
        return *this;
    }
    template<typename F, typename ...Args>
    IGroup<T>& operator () (F functor, Args... args)
    {
        for (auto tmp : *this)
            functor(tmp, args...);
        return *this;
    }
    template<typename O, std::enable_if_t<std::is_base_of<O, T>::value, bool> = true>
    operator IGroup<O, iterator::group_iterator<O*, T**>>()
    {
        return {&*m_begin, &*m_end};
    }
protected:
    IGroup(T** beg, T** end): m_begin{beg}, m_end{end} {}
    IT m_begin, m_end;
};


using Group_I = IGroup<Entry>;

template< int N, typename T = Entry, std::enable_if_t<(N > 0), bool> = true>
class Group : public IGroup<T> {
    T* m_group[N];
    template<int H, int M>
    friend Group<H+M, T> operator&(const Group<H, T>& f, const Group<M, T>& s);
public:
    template <typename ...Args>
    explicit Group(Args&... args) : IGroup<T>{m_group, m_group + N},m_group{(static_cast<T*>(&args))... }{}
};

template<typename ...Args> Group(Args&... ) -> Group <sizeof...( Args )>;

template<int H, int M, typename T>
Group<H+M, T> operator&(const Group<H, T>& f, const Group<M, T>& s)
{
    Group<H+M, T> group;
    auto& it = group.begin();
    for (auto& item : f.m_group)
        * ( it++ ) = item;
    for (auto& item : s.m_group)
        * ( it++ ) = item;
    return group;
}


static auto drew{[](Entry* ent){ent->draw();}};
static auto hand{[](Entry* ent){ent->handle();}};