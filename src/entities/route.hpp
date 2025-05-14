#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include "common/math/math.hpp"
#include "entities/base.hpp"

class Route : public Base
{
private:
    std::string route_name;
    double distance = 0.0;

public:
    Route(
        const std::string &id,
        const std::string &route_name);
    ~Route() = default;

public:
    std::string getRouteName() const;
    double getDistance() const;
    void setDistance(const std::vector<std::vector<int>>& positions);

public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Route> deserialize(const std::string &data);
};
