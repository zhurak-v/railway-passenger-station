#include "entities/station.hpp"

Station::Station(
    const std::string& id,
    const std::string& station_name,
    Position position
) : Base(id),
    station_name(station_name), position(position) {};

std::string Station::getStationName() const {
    return station_name;
}

Position Station::getPosition() const {
    return position;
}

std::string Station::staticClass() {
    return "Station";
}

std::string Station::getClass() const { 
    return staticClass();
}