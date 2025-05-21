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
    status(status) {
        int h = this->status.getDelayTime().getHour();
        int m = this->status.getDelayTime().getHour();
        this->departure_time.setHour(this->departure_time.getHour() + h);
        this->departure_time.setMinute(this->departure_time.getMinute() + m);
    };

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