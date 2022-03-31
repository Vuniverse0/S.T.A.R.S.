#pragma once

#include "../primitives/Entry.h"


struct Group_I{
    Entry **begin{nullptr}, **end{nullptr};
    template<typename F>
    Group_I& operator | (F functor) {
        for (auto tmp = begin; tmp != end; ++tmp)
            functor(*tmp);
        return *this;
    }
};

template< int N>
class Group : public Group_I {
    Entry* m_group[N];
public:
    template<typename ...Args>
    Group(Args&... args): m_group{(&args)... }{begin = m_group; end = m_group + N;}
};