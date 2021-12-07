//
// Created by vuniverse on 12/6/21.
//

#pragma once


template<class ... Ts>
struct overloaded : Ts ...
{
    using Ts::operator()... ;
};
template<class ... Ts>
overloaded(Ts ... ) -> overloaded<Ts ... >;