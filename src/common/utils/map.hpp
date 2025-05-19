#pragma once
#include <vector>
#include <memory>

template<typename T, typename U>
std::vector<U> map(const std::vector<std::shared_ptr<T>>& input, U (*func)(const T&)) {
    std::vector<U> result;
    result.reserve(input.size());
    for (const auto& item : input) {
        result.push_back(func(*item));
    }
    return result;
}