#include "entities/station.hpp"

Station::Station(
    const std::string& id,
    const std::string& station_name,
    const int position
) : Base(id),
    station_name(station_name), position(position) {};

std::string Station::getStationName() const {
    return station_name;
}
int Station::getPosition() const {
    return position;
}