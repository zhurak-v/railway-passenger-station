#pragma once
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "common/utils/weak.hpp"
#include "common/relation/base-relation.hpp"

template <typename A, typename B>
class ManyToMany : public BaseRelation<A, B> {
    using APtr = std::shared_ptr<A>;
    using BPtr = std::shared_ptr<B>;
    using AWeak = std::weak_ptr<A>;
    using BWeak = std::weak_ptr<B>;

    std::unordered_map<AWeak, std::unordered_set<BWeak, WeakHash, WeakEqual>, WeakHash, WeakEqual> a_to_b;
    std::unordered_map<BWeak, std::unordered_set<AWeak, WeakHash, WeakEqual>, WeakHash, WeakEqual> b_to_a;

public:
    void link(const APtr &a, const BPtr &b) override {
        if (!a || !b) return;
        a_to_b[a].insert(b);
        b_to_a[b].insert(a);
    }

    void unlink(const APtr &a) override {
        if (!a) return;
        auto it = a_to_b.find(a);
        if (it != a_to_b.end()) {
            for (const auto &b : it->second) {
                if (auto b_sp = b.lock()) b_to_a[b_sp].erase(a);
            }
            a_to_b.erase(it);
        }
    }

    void unlink(const BPtr &b) override {
        if (!b) return;
        auto it = b_to_a.find(b);
        if (it != b_to_a.end()) {
            for (const auto &a : it->second) {
                if (auto a_sp = a.lock()) a_to_b[a_sp].erase(b);
            }
            b_to_a.erase(it);
        }
    }

    std::vector<BPtr> getLinkedB(const APtr &a) const {
        std::vector<BPtr> result;
        if (!a) return result;
        auto it = a_to_b.find(a);
        if (it != a_to_b.end()) {
            for (const auto &b : it->second) {
                if (auto b_sp = b.lock()) result.push_back(b_sp);
            }
        }
        return result;
    }

    std::vector<APtr> getLinkedA(const BPtr &b) const {
        std::vector<APtr> result;
        if (!b) return result;
        auto it = b_to_a.find(b);
        if (it != b_to_a.end()) {
            for (const auto &a : it->second) {
                if (auto a_sp = a.lock()) result.push_back(a_sp);
            }
        }
        return result;
    }
};
