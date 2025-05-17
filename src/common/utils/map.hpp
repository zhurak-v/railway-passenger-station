#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include <utility>

template<typename T, typename Func>
auto map(const std::vector<std::shared_ptr<T>>& input, Func func) {
    using U = decltype(func(*std::declval<std::shared_ptr<T>>()));
    std::vector<U> result;
    result.reserve(input.size());
    for (const auto& item : input) {
        result.push_back(func(*item));
    }
    return result;
}