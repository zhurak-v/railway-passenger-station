#include "entities/trip.hpp"
#include "common/date/date.hpp"
#include <iomanip>

std::string Trip::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << std::quoted(getTripName()) << " "
        << getDepartureTime().serialize() << " "
        << static_cast<int>(getTripStatus()) << " "
        << std::quoted(getTripReason()) << " "
        << getDelayTime().serialize();

    return oss.str();
}

std::shared_ptr<Trip> Trip::deserialize(const std::string &data)
{
    std::istringstream iss(data);

    std::string id;
    iss >> id;

    std::string trip_name;
    iss >> std::quoted(trip_name);

    std::string departure_time_str;
    iss >> departure_time_str;

    int status_int;
    iss >> status_int;

    std::string trip_reason;
    iss >> std::quoted(trip_reason);

    std::string delay_time_str;
    iss >> delay_time_str;

    Date departure_time = Date::deserialize(departure_time_str);
    Date delay_time = Date::deserialize(delay_time_str);

    TripStatus status(static_cast<Status>(status_int), trip_reason, delay_time);

    return std::make_shared<Trip>(id, trip_name, departure_time, status);
}
