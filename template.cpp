//
//  template.cpp
//  Some helper classes to extract the first, nth or last template argument.
//
//  Created by samuel.
//  Copyright (c) 2014 SDS. All rights reserved.
//

#include <cstdlib>          // EXIT_SUCCESS
#include <type_traits>      // is_same<>


/// Returns the nth type.
template<std::size_t n, typename ...Args>
struct nth_type;

template<typename T, typename... Args>
struct nth_type<1,T,Args...> {
    typedef T type;
};

template<std::size_t n, typename T, typename... Args>
struct nth_type<n,T,Args...> : nth_type<n-1,Args...> {
    static_assert( n>0,"n shall be greater to 0" );
};

/// Returns the last type.
template <typename... Args>
struct last_type;

template <typename T>
struct last_type<T> {
    typedef T type;
};

template <typename T, typename... Args>
struct last_type<T, Args...> : last_type<Args...> {};

/// Returns the first type.
template<typename T, typename... Args>
struct first_type {
    typedef T type;
};

int main()
{
    // Doesn't have to be in the main...
    // Tests nth_type struct
    {
        using result_type = nth_type<3,int,unsigned,double,float>::type;
        static_assert(std::is_same<double,result_type>::value,"");
    }
    
    // Tests last_type struct
    {
        using result_type = last_type<int,unsigned,double,float>::type;
        static_assert(std::is_same<float,result_type>::value,"");
    }
    
    // Tests first_type struct
    {
        using result_type = first_type<int,unsigned,double,float>::type;
        static_assert(std::is_same<int,result_type>::value,"");
    }
    
    return EXIT_SUCCESS;
}