
// Copyright (c) Microsoft Open Technologies, Inc. All rights reserved. See License.txt in the project root for license information.

#pragma once

#if !defined(RXCPP_RX_SOURCES_HPP)
#define RXCPP_RX_SOURCES_HPP

#include "rx-includes.hpp"

namespace rxcpp {

namespace sources {

struct tag_source {};
template<class T>
struct source_base
{
    typedef T value_type;
    typedef tag_source source_tag;
};
template<class T>
class is_source
{
    template<class C>
    static typename C::source_tag check(int);
    template<class C>
    static void check(...);
public:
    static const bool value = std::is_convertible<decltype(check<T>(0)), tag_source>::value;
};

}
namespace rxs=sources;

}

#include "sources/rx-range.hpp"

#endif