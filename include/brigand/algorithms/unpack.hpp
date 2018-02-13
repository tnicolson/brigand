/*!
  @file

  @copyright Edouard Alligand and Joel Falcou 2015-2018
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_BRIGAND_ALGORITHMS_UNPACK_HPP
#define BOOST_BRIGAND_ALGORITHMS_UNPACK_HPP

#include <brigand/types/integral_constant.hpp>
#include <brigand/types/type.hpp>

namespace brigand
{

    namespace detail
    {
        template<typename T>
        struct unpack_type {
            using type = type_<T>;
        };

        template<typename T, T I>
        struct unpack_type<integral_constant<T, I>> {
            using type = integral_constant<T, I>;
        };

        template<template<class...> class List, typename... Elements, typename Functor>
        decltype(auto) unpack_impl( List<Elements...>&&, Functor f )
        {
            return f(typename unpack_type<Elements>::type()...);
        }
    }

    template<typename List, typename Functor>
    decltype(auto) unpack( Functor f )
    {
        return detail::unpack_impl( List{}, f );
    }

}
#endif
