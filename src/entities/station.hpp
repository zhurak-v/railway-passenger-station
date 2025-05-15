#pragma once

#include <string>
#include <memory>
#include <vector>
#include "entities/base.hpp"
#include "common/date/date.hpp"
#include "entities/position.hpp"

class Station : public Base
{
private:
    std::string station_name;
    Position position;

public:
    Station(
        const std::string& id,
        const std::string& station_name,
        Position position
    );
    ~Station() = default;

public:
    std::string getStationName() const;
    Position getPosition() const;

public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Station> deserialize(const std::string &data);
};
