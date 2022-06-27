#pragma once

#include "Entry.h"

namespace iterator{
    template<typename N>
    struct group_iterator{
        template<typename T,
                    std::enable_if_t<
                        std::is_base_of<
                            T,
                            std::remove_pointer_t<N>
                        >::value,
                        bool
                    > = true
                >
        operator group_iterator<T>()
        {
            struct fake_iterator:group_iterator<N>{
                using Type = T;
                Type& operator*(){ return *m_pointer; }
                const Type& operator*() const{ return *m_pointer; }
            };
            return fake_iterator{m_pointer};
        }

        explicit group_iterator(N* pointer) : m_pointer{ pointer } {}

        virtual N& operator*(){ return *m_pointer; }
        virtual const N& operator*() const{ return *m_pointer; }

        group_iterator<N> operator++(int) { return ++m_pointer; };
        group_iterator& operator++() { m_pointer++; return *this; };

        group_iterator<N> operator--(int){ return --m_pointer; };
        group_iterator& operator--(){ m_pointer--; return *this; };

        group_iterator<N> operator+(size_t n) const{ return {m_pointer+n}; };
        group_iterator<N> operator-(size_t n) const{ return {m_pointer-n}; };
        size_t operator-(group_iterator<N> n) const{ return static_cast<size_t>(m_pointer - n.m_pointer); };

        group_iterator& operator+=(size_t n){m_pointer+=n; return *this; };
        group_iterator& operator-=(size_t n){m_pointer-=n; return *this; };


        template<typename T>
        bool operator>(group_iterator<T> a) const{ return m_pointer > a.m_pointer;}
        template<typename T>
        bool operator<(group_iterator<T> a) const{ return m_pointer < a.m_pointer;}

        template<typename T>
        bool operator>=(group_iterator<T> a) const{ return m_pointer >= a.m_pointer;}
        template<typename T>
        bool operator<=(group_iterator<T> a) const{ return m_pointer <= a.m_pointer;}

        template<typename T>
        bool operator==(group_iterator<T> a) const{ return m_pointer == a.m_pointer;}
        template<typename T>
        bool operator!=(group_iterator<T> a) const{ return m_pointer != a.m_pointer;}
    private:
        N* m_pointer;
    };
}

template<typename T>
struct IGroup{
    using IT = iterator::group_iterator<T*>;
    IT begin() const{ return m_begin; };
    IT end() const{ return m_end; };
    const IT cbegin() const{ return m_begin; };
    const IT cend() const{ return m_end; };
    template<typename F>
    IGroup<T>& operator | (F functor)
    {
        for (auto tmp : *this)
            functor(tmp);
        return *this;
    }
    template<typename O, std::enable_if_t<std::is_base_of<O, T>::value, bool> = true>
    operator IGroup<O>() const
    {
        return {&*m_begin, &*m_end};
    }
    template<typename O, std::enable_if_t<std::is_base_of<T, O>::value, bool> = true>
    IGroup(const IGroup<O>& arg) : IGroup{arg.begin(), arg.end()}{}
    [[nodiscard]] size_t size()const{return size_t{m_end - m_begin};}
protected:
    IGroup(T** beg, T** end): m_begin{beg}, m_end{end} {}
    IGroup(IT beg, IT end): m_begin{beg}, m_end{end} {}
    IT m_begin, m_end;
};


using Group_I = IGroup<Entry>;

template<typename T = Entry, size_t N = 0, std::enable_if_t<(N > 0), bool> = true>
class Group : public IGroup<T> {
    T* m_group[N];
    template<size_t H, size_t M>
    friend Group<T, H+M> operator+(const Group<T, H>& f, const Group<T, M>& s);
    template<size_t H, size_t M>
    friend Group<T, H> operator-(const Group<T, H>& f, const Group<T, M>& s);
    template<size_t H, size_t M>
    friend Group<T, H+M> operator&&(const Group<T, H>& f, const Group<T, M>& s);
public:
    template <typename ...Args>
    explicit Group(Args&... args) : IGroup<T>{m_group, m_group + N},m_group{(static_cast<T*>(&args))... }{}
    explicit Group() : IGroup<T>{m_group, m_group},m_group{}{for (auto& item : m_group) item = nullptr;}
    template<typename O, std::enable_if_t<std::is_base_of<O, T>::value, bool> = true>
    operator IGroup<O>() const
    {
        return getI();
    }
    const IGroup<T>& getI() const
    {
        return *this;
    }

    size_t push_back(T& t)//return empty size
    {
        if (IGroup<T>::m_end - IGroup<T>::m_begin < N) {
            (IGroup<T>::m_end++) = &t;
            return N - IGroup<T>::m_end - IGroup<T>::m_begin;
        }
        else {
            return -1;
        }
    }

    template<typename ...Args>
    size_t push_back(Args&... t)//return empty size
    {
        auto pack = [&](auto& temp){(IGroup<T>::m_end++) = &temp;};
        if (IGroup<T>::m_end - IGroup<T>::m_begin + sizeof...(Args) < N) {
            (pack(t),...);//TODO test these
            return N - IGroup<T>::m_end - IGroup<T>::m_begin;
        }
        else {
            return -1;
        }
    }

    T* pop_back(){
        auto& tmp = *IGroup<T>::m_end;
        (IGroup<T>::m_end--) = nullptr;
        return tmp;
    }

    constexpr size_t size()const{return N;}
};


//template<typename ...Args> Group(Args&... ) -> Group <Entry, sizeof...( Args )>;

template<typename T, typename ...Args> Group(T& head, Args&... ) -> Group <T, sizeof...( Args ) + 1>;

template<size_t H, size_t M, typename T>
Group<T, H+M> operator+(const Group<T, H>& f, const Group<T, M>& s)
{
    Group<T, H+M> group;
    auto& it = group.begin();
    for (auto item : f.m_group)
        * ( it++ ) = item;
    for (auto item : s.m_group)
        * ( it++ ) = item;
    return group;
}

template<size_t H, size_t M, typename T>
Group<T, H> operator-(const Group<T, H>& f, const Group<T, M>& s)
{
    Group<T, H> group;
    for (auto itemf : f.m_group) {
        for (auto items: s.m_group) if (itemf == items) goto label;
        group.push_back(itemf);
        label:
        continue;
    }
    return group;
}

template<size_t H, size_t M, typename T>
Group<T, H+M> operator&&(const Group<T, H>& f, const Group<T, M>& s)//only elements what are in both, without duplicates
{
    Group<T, H+M> group;
    for (auto itemf : f.m_group) {
        for (auto items: s.m_group)
            if (itemf == items) {
                for (auto item: group.m_group)
                    if (itemf == item) goto label;
                group.push_back(*itemf);
            }
        label:
        continue;
    }
    return group;
}