#pragma once
#include <memory>
#include <functional>

struct WeakHash {
    template <typename T>
    std::size_t operator()(const std::weak_ptr<T>& wp) const {
        auto sp = wp.lock();
        return std::hash<T*>()(sp.get());
    }
};

struct WeakEqual {
    template <typename T>
    bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const {
        return lhs.lock().get() == rhs.lock().get();
    }
};
