#include "entities/station.hpp"
#include <iomanip>

std::string Station::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << std::quoted(getStationName()) << " "
        << getPosition().getX() << " " << getPosition().getY();

    return oss.str();
}

std::shared_ptr<Station> Station::deserialize(const std::string &data)
{
    std::istringstream iss(data);

    std::string id;
    iss >> id;

    std::string station_name;
    iss >> std::quoted(station_name);

    double x, y;
    iss >> x >> y;

    Position position(x, y);
    return std::make_shared<Station>(id, station_name, position);
}
