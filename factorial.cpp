//
//  factorial.cpp
//  Compute factorial numbers at compile time (using meta-template)
//  or at running and compile time with constexpr function template (c++11).
//  Created by samuel.
//  Copyright (c) 2014 SDS. All rights reserved.
//

#include <cstdlib>      // EXIT_SUCCESS

template <unsigned n, typename T = uintmax_t>
struct factorial
{
    static const T value = n * factorial<n-1>::value;
};

template <typename T>
struct factorial<1,T>
{
    static const T value = 1;
};

template<typename T = uintmax_t>
constexpr T factorial_func(T n) {
    return n ? n * factorial_func(n-1) : 1;
};



static_assert(factorial<3,unsigned>::value == 6, "");
static_assert(factorial_func(4) == 24, "");
static_assert(factorial_func<uintmax_t>(13) == 6227020800, "");

int main()
{
    return EXIT_SUCCESS;
}