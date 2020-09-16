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
/// @file ut_then.hpp
///

#ifndef BSL_UT_THEN_HPP
#define BSL_UT_THEN_HPP

namespace bsl
{
    /// @class bsl::ut_then
    ///
    /// <!-- description -->
    ///   @brief Defines the expected "result" of a unit test scenario.
    ///
    class ut_then final
    {
    public:
        /// <!-- description -->
        ///   @brief Default constructor
        ///
        constexpr ut_then() noexcept = default;

        /// <!-- description -->
        ///   @brief Executes a lambda function as the body of the
        ///     "then" portion of the scenario.
        ///
        /// <!-- inputs/outputs -->
        ///   @tparam FUNC_T the type of lambda being executed
        ///   @param func the lambda being executed
        ///   @return Returns a reference to the ut_then.
        ///
        template<typename FUNC_T>
        [[maybe_unused]] constexpr auto
        operator=(FUNC_T &&func) &&noexcept -> ut_then &
        {
            func();
            return *this;
        }

        /// @brief the l-value version of this function is not supported
        template<typename FUNC_T>
        [[maybe_unused]] constexpr auto operator=(FUNC_T &&func) const &noexcept
            -> ut_then & = delete;

        /// <!-- description -->
        ///   @brief Destroyes a previously created bsl::ut_then
        ///
        constexpr ~ut_then() noexcept = default;

        /// <!-- description -->
        ///   @brief copy constructor
        ///
        /// <!-- inputs/outputs -->
        ///   @param o the object being copied
        ///
        constexpr ut_then(ut_then const &o) noexcept = default;

        /// <!-- description -->
        ///   @brief move constructor
        ///
        /// <!-- inputs/outputs -->
        ///   @param o the object being moved
        ///
        constexpr ut_then(ut_then &&o) noexcept = default;

        /// <!-- description -->
        ///   @brief copy assignment
        ///
        /// <!-- inputs/outputs -->
        ///   @param o the object being copied
        ///   @return a reference to *this
        ///
        [[maybe_unused]] constexpr auto operator=(ut_then const &o) &noexcept
            -> ut_then & = default;

        /// <!-- description -->
        ///   @brief move assignment
        ///
        /// <!-- inputs/outputs -->
        ///   @param o the object being moved
        ///   @return a reference to *this
        ///
        [[maybe_unused]] constexpr auto operator=(ut_then &&o) &noexcept -> ut_then & = default;
    };
}

#endif
