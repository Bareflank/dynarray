/// @copyright
/// Copyright (C) 2020 Assured Information Security, Inc.
///
/// @copyright
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// @copyright
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// @copyright
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.
///
/// @file move_if_noexcept.hpp
///

#ifndef BSL_MOVE_IF_NOEXCEPT_HPP
#define BSL_MOVE_IF_NOEXCEPT_HPP

#include "bsl/conditional.hpp"
#include "bsl/conjunction.hpp"
#include "bsl/is_copy_constructible.hpp"
#include "bsl/is_nothrow_move_constructible.hpp"
#include "bsl/move.hpp"
#include "bsl/negation.hpp"

namespace bsl
{
    /// <!-- description -->
    ///   @brief move_if_noexcept obtains an rvalue reference to its argument
    ///     if its move constructor does not throw exceptions or if there is
    ///     no copy constructor (move-only type), otherwise obtains an lvalue
    ///     reference to its argument. It is typically used to combine move
    ///     semantics with strong exception guarantee.
    ///   @include example_move_if_noexcept_overview.hpp
    ///
    /// <!-- inputs/outputs -->
    ///   @tparam T the type that defines the value being moved
    ///   @param mut_val the value being moved
    ///   @return std::move(mut_val) or mut_val, depending on exception guarantees.
    ///
    template<typename T>
    [[nodiscard]] constexpr auto
    move_if_noexcept(T &mut_val) noexcept -> conditional_t<
        conjunction<negation<is_nothrow_move_constructible<T>>, is_copy_constructible<T>>::value,
        T const &,
        T &&>
    {
        return move(mut_val);
    }
}

#endif
