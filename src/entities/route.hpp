#pragma once

#include "entities/base.hpp"
#include <string>
#include <memory>
#include <vector>

class Route : public Base
{
private:
    std::string route_name;

public:
    Route(
        const std::string &id,
        const std::string &route_name);
    ~Route() = default;

public:
    std::string getRouteName() const;

public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Route> deserialize(const std::string &data);
};
