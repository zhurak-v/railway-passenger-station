#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include "common/math/math.hpp"
#include "common/date/date.hpp"
#include "entities/base.hpp"
#include "entities/position.hpp"

enum class TypeRoute
{
    Domestic,
    International,
    Tourist,
    Special,
};

class Route : public Base
{
private:
    std::string route_name;
    TypeRoute type_route;

public:
    Route(
        const std::string &id,
        const std::string &route_name,
        const TypeRoute& type_route
    );
    ~Route() = default;

public:
    std::string getRouteName() const;
    TypeRoute getTypeRoute() const;

public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Route> deserialize(const std::string &data);
};
