#pragma once
#include <memory>
#include <unordered_map>
#include <vector>
#include "common/utils/weak.hpp"
#include "common/relation/base-relation.hpp"

template <typename A, typename B>
class OneToOne : public BaseRelation<A, B> {
    using APtr = std::shared_ptr<A>;
    using BPtr = std::shared_ptr<B>;
    using AWeak = std::weak_ptr<A>;
    using BWeak = std::weak_ptr<B>;

    std::unordered_map<AWeak, BWeak, WeakHash, WeakEqual> a_to_b;
    std::unordered_map<BWeak, AWeak, WeakHash, WeakEqual> b_to_a;

public:
    void link(const APtr& a, const BPtr& b) {
        if (!a || !b) return;
        unlink(a);
        unlink(b);
        a_to_b[a] = b;
        b_to_a[b] = a;
    }

    void unlink(const APtr& a) {
        if (!a) return;
        auto it = a_to_b.find(a);
        if (it != a_to_b.end()) {
            b_to_a.erase(it->second);
            a_to_b.erase(it);
        }
    }

    void unlink(const BPtr& b) {
        if (!b) return;
        auto it = b_to_a.find(b);
        if (it != b_to_a.end()) {
            a_to_b.erase(it->second);
            b_to_a.erase(it);
        }
    }

    BPtr getLinkedB(const APtr& a) const {
        if (!a) return nullptr;
        auto it = a_to_b.find(a);
        return it != a_to_b.end() ? it->second.lock() : nullptr;
    }

    APtr getLinkedA(const BPtr& b) const {
        if (!b) return nullptr;
        auto it = b_to_a.find(b);
        return it != b_to_a.end() ? it->second.lock() : nullptr;
    }

    const std::unordered_map<AWeak, BWeak, WeakHash, WeakEqual>& getAMap() const 
    {
        return a_to_b;
    }
    
    const std::unordered_map<BWeak, AWeak, WeakHash, WeakEqual>& getBMap() const {
        return b_to_a;
    }
};