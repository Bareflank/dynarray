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

#include <bsl/convert.hpp>
#include <bsl/debug.hpp>
#include <bsl/safe_integral.hpp>
#include <bsl/unlikely.hpp>

namespace bsl
{
    /// <!-- description -->
    ///   @brief Provides the example's main function
    ///
    inline void
    example_safe_integral_is_zero_or_poisoned() noexcept
    {
        auto mut_val1{bsl::safe_i32::failure()};
        auto mut_val2{bsl::safe_i32::magic_0()};
        auto mut_val3{bsl::safe_i32::magic_1()};

        auto mut_val4{42_i32 + 42_i32};
        if (bsl::unlikely(mut_val4.is_zero_or_poisoned())) {
            bsl::error() << "failure\n";
        }
        else {
            bsl::print() << "success\n";
        }

        if (mut_val1.is_zero_or_poisoned()) {
            bsl::print() << "success\n";
        }
        else {
            bsl::error() << "failure\n";
        }

        if (mut_val2.is_zero_or_poisoned()) {
            bsl::print() << "success\n";
        }
        else {
            bsl::error() << "failure\n";
        }

        if (!mut_val3.is_zero_or_poisoned()) {
            bsl::print() << "success\n";
        }
        else {
            bsl::error() << "failure\n";
        }

        if (mut_val4.is_checked()) {
            bsl::print() << "success\n";
        }
        else {
            bsl::error() << "failure\n";
        }
    }
}
