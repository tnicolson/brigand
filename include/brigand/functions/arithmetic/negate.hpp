/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#ifndef BOOST_BRIGAND_FUNCTIONS_ARITHMETIC_NEGATE_HPP
#define BOOST_BRIGAND_FUNCTIONS_ARITHMETIC_NEGATE_HPP
#include <brigand/types/integral_constant.hpp>

namespace brigand
{
template <typename A>
struct negate : brigand::integral_constant<typename A::value_type, -A::value>
{
};
}
#endif
