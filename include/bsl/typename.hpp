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

#ifndef BSL_TYPENAME_HPP
#define BSL_TYPENAME_HPP

#include <bsl/string_view.hpp>

namespace bsl
{
    /// <!-- description -->
    ///   @brief Returns a bsl::string_view containing the name of the
    ///     the provided type.
    ///
    /// <!-- inputs/outputs -->
    ///   @return Returns a bsl::string_view containing the name of the
    ///     the provided type.
    ///
    template<typename T>
    [[nodiscard]] constexpr auto
    type_name() noexcept -> auto
    {
        constexpr bsl::string_view prefix{"auto bsl::type_name() [T = "};
        constexpr bsl::string_view suffix{"]"};

        bsl::string_view name{__PRETTY_FUNCTION__};
        name.remove_prefix(bsl::to_idx(prefix.size()));
        name.remove_suffix(bsl::to_idx(suffix.size()));

        return name;
    }
}

#endif
