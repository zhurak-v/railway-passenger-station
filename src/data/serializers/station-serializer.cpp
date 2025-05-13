#include "entities/station.hpp"
#include "common/date/date.hpp"


std::string Station::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << getStationName() << " " << getPosition();

    return oss.str();
}

std::shared_ptr<Station> Station::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string station_name;
    int position;

    iss >> id >> station_name >> position;

    return std::make_shared<Station>(id, station_name, position);
}