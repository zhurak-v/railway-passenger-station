#include "entities/station.hpp"

std::string Station::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << getStationName() << " " << getPosition()[0] << " " << getPosition()[1];;

    return oss.str();
}

std::shared_ptr<Station> Station::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string station_name;
    int x, y;

    iss >> id >> station_name >> x >> y;
    std::vector<int> position = {x, y};

    return std::make_shared<Station>(id, station_name, position);
}