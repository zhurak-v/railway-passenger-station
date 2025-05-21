#pragma once
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include "common/utils/weak.hpp"
#include "common/relation/base-relation.hpp"

template <typename A, typename B>
class OneToMany : public BaseRelation<A, B>
{
    using APtr = std::shared_ptr<A>;
    using BPtr = std::shared_ptr<B>;
    using AWeak = std::weak_ptr<A>;
    using BWeak = std::weak_ptr<B>;

    std::unordered_map<AWeak, std::vector<BWeak>, WeakHash, WeakEqual> a_to_b;
    std::unordered_map<BWeak, AWeak, WeakHash, WeakEqual> b_to_a;
    std::unordered_map<AWeak, std::unordered_set<BWeak, WeakHash, WeakEqual>, WeakHash, WeakEqual> a_to_b_set;

public:
    void link(const APtr &a, const BPtr &b) override
    {
        if (!a || !b)
            return;
        unlink(b);
        if (a_to_b_set[a].insert(b).second) {
            a_to_b[a].push_back(b);
        }
        b_to_a[b] = a;
    }

    void unlink(const APtr &a) override
    {
        if (!a)
            return;
        auto it = a_to_b.find(a);
        if (it != a_to_b.end())
        {
            for (const auto &b : it->second)
            {
                b_to_a.erase(b);
            }
            a_to_b.erase(it);
            a_to_b_set.erase(a);
        }
    }

    void unlink(const BPtr &b) override
    {
        if (!b)
            return;
        auto it = b_to_a.find(b);
        if (it != b_to_a.end())
        {
            auto a = it->second;
            if (auto a_sp = a.lock()) {
                a_to_b[a_sp].erase(std::remove_if(a_to_b[a_sp].begin(), a_to_b[a_sp].end(), 
                    [&b](const BWeak& weak) { return weak.lock() == b; }), 
                    a_to_b[a_sp].end());
                a_to_b_set[a_sp].erase(b);
            }
            b_to_a.erase(it);
        }
    }

    std::vector<BPtr> getLinkedB(const APtr &a) const
    {
        std::vector<BPtr> result;
        if (!a)
            return result;
        auto it = a_to_b.find(a);
        if (it != a_to_b.end())
        {
            for (const auto &b : it->second)
            {
                if (auto b_sp = b.lock())
                    result.push_back(b_sp);
            }
        }
        return result;
    }

    APtr getLinkedA(const BPtr &b) const
    {
        if (!b)
            return nullptr;
        auto it = b_to_a.find(b);
        return it != b_to_a.end() ? it->second.lock() : nullptr;
    }

    const std::unordered_map<AWeak, std::vector<BWeak>, WeakHash, WeakEqual> &getAMap() const
    {
        return a_to_b;
    }

    const std::unordered_map<BWeak, AWeak, WeakHash, WeakEqual> &getBMap() const
    {
        return b_to_a;
    }
};