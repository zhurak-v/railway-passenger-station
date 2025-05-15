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

class Route : public Base
{
private:
    std::string route_name;
    double distance;
    std::vector<double> distances;

public:
    Route(
        const std::string &id,
        const std::string &route_name);
    ~Route() = default;

public:
    std::string getRouteName() const;
    Date getDuration() const;
    double getDistance() const;
    std::vector<double> getDistances() const;
    
    void setDistance(const std::vector<Position>& positions);

public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Route> deserialize(const std::string &data);
};
