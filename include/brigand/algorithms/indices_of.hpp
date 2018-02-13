/*!
@file

@copyright Edouard Alligand and Joel Falcou 2015-2018
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_BRIGAND_ALGORITHMS_INDICES_OF_HPP
#define BOOST_BRIGAND_ALGORITHMS_INDICES_OF_HPP

#include <brigand/types/integer.hpp>
#include <brigand/types/no_such_type.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/functions/lambda.hpp>
#include <brigand/functions/if.hpp>
#include <brigand/functions/arithmetic/next.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/algorithms/fold.hpp>

namespace brigand
{
namespace detail
{

    template<typename Indices, typename Index>
    struct indices_builder {
        using type = Indices;
        using index = Index;
    };

    template<typename S>
    struct indices_add {
        using type = indices_builder<
            push_back<typename S::type, typename S::index>
          , typename next<typename S::index>::type
        >;
    };

    template<typename S>
    struct indices_skip {
        using type = indices_builder<
            typename S::type
          , typename next<typename S::index>::type
        >;
    };

    // TODO Shouldn't need this...?
    template<typename Lambda, typename T>
    struct apply_to : brigand::apply<Lambda, T>::type {};

    template<typename Sequence, typename Predicate>
    using indices_if_impl = fold<Sequence,
                                 indices_builder<integral_list<std::size_t>, size_t<0>>,
                                 if_<apply_to<defer<Predicate>, _element>,
                                     indices_add<_state>,
                                     indices_skip<_state>>>;

} // namespace detail

template <class Sequence, class Predicate>
using indices_if = typename detail::indices_if_impl<Sequence, Predicate>::type;

template <class Sequence, typename T>
using indices_of = indices_if<Sequence, std::is_same<typename brigand::pin<T>, ::brigand::_1>>;

} // namespace brigand
#endif
