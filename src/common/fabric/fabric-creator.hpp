#pragma once

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include "entities/base.hpp"

class EntityFactory {
public:
    using Creator = std::function<std::shared_ptr<Base>(const std::string&)>;

    static EntityFactory& instance();

    void registerClass(const std::string& class_name, Creator creator);
    std::shared_ptr<Base> create(const std::string& class_name, const std::string& data) const;

private:
    EntityFactory() = default;
    std::unordered_map<std::string, Creator> creators;
};
