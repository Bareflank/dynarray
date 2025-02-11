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

#include "../class_base.hpp"
#include "../class_subclass.hpp"
#include "../fmt_test.hpp"

#include <bsl/convert.hpp>
#include <bsl/safe_integral.hpp>
#include <bsl/ut.hpp>

namespace
{
    /// <!-- description -->
    ///   @brief Used to execute the actual checks. We put the checks in this
    ///     function so that we can validate the tests both at compile-time
    ///     and at run-time. If a bsl::ut_check fails, the tests will either
    ///     fail fast at run-time, or will produce a compile-time error.
    ///
    /// <!-- inputs/outputs -->
    ///   @return Always returns bsl::exit_success.
    ///
    [[nodiscard]] constexpr auto
    tests() noexcept -> bsl::exit_code
    {
        bsl::ut_scenario{"reset"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                fmt_test::reset();
            };
        };

        bsl::ut_scenario{"was_this_outputted"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::ut_when{} = []() noexcept {
                    fmt_test::reset();
                    bsl::details::redirected_out_char('h');
                    bsl::ut_then{} = []() noexcept {
                        bsl::ut_check(fmt_test::was_this_outputted("h"));
                        bsl::ut_check(!fmt_test::was_this_outputted("w"));
                        bsl::ut_check(!fmt_test::was_this_outputted("world"));
                    };
                };
            };
        };

        bsl::ut_scenario{"was_this_outputted"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                constexpr auto len{5_umx};
                bsl::ut_when{} = [&]() noexcept {
                    fmt_test::reset();
                    bsl::details::redirected_out_cstr("hello", len.get());
                    bsl::ut_then{} = []() noexcept {
                        bsl::ut_check(fmt_test::was_this_outputted("hello"));
                        bsl::ut_check(!fmt_test::was_this_outputted("w"));
                        bsl::ut_check(!fmt_test::was_this_outputted("world"));
                    };
                };
            };
        };

        bsl::ut_scenario{"class_base"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                test::class_base const base{};
                auto const *const ptr{new test::class_base};
                // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
                delete ptr;    // GRCOV_EXCLUDE_BR
            };
        };

        bsl::ut_scenario{"class_subclass"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                test::class_subclass const subclass{};
                auto const *const ptr{new test::class_subclass};
                // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
                delete ptr;    // GRCOV_EXCLUDE_BR
            };
        };

        return bsl::ut_success();
    }
}

/// <!-- description -->
///   @brief Main function for this unit test. If a call to bsl::ut_check() fails
///     the application will fast fail. If all calls to bsl::ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
[[nodiscard]] auto
main() noexcept -> bsl::exit_code
{
    static_assert(tests() == bsl::ut_success());
    return tests();
}
