#pragma once
#include <memory>
#include "common/utils/weak.hpp"

template <typename A, typename B>
class BaseRelation {
public:
    virtual void link(const std::shared_ptr<A>& a, const std::shared_ptr<B>& b) = 0;
    virtual void unlink(const std::shared_ptr<A>& a) = 0;
    virtual void unlink(const std::shared_ptr<B>& b) = 0;
    virtual ~BaseRelation() = default;
};
