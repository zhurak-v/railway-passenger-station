#include "entities/trip.hpp"

Trip::Trip(
    const std::string& id,
    const std::string& trip_name,
    const Date& departure_time,
    const Date& break_duration,
    const TripStatus& status) : 
    Base(id),
    trip_name(trip_name), 
    departure_time(departure_time), 
    break_duration(break_duration),
    status(status) {};

std::string Trip::getTripName() const {
    return trip_name;
}

Date Trip::getDepartureTime() const {
    return departure_time;
}

Status Trip::getTripStatus() const {
    return status.getStatus();
};
std::string Trip::getTripReason() const {
    return status.getReason();
}

Date Trip::getDelayTime() const {
    return status.getDelayTime();
}

Date Trip::getBreakDuration() const {
    return break_duration;
}

std::string Trip::staticClass() {
    return "Trip";
}

std::string Trip::getClass() const { 
    return staticClass();
}