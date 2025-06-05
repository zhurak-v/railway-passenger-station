#include "entities/trip-status.hpp"

TripStatus::TripStatus() : 
    status(Status::Active), 
    reason("Everything is fine."), 
    delay_time(Date(0, 0)) {}

TripStatus::TripStatus(
    const Status& status, 
    const std::string& reason, 
    const Date& delay_time )
    : status(status), reason(reason), delay_time(delay_time) {}

Status TripStatus::getStatus() const {
    return status;
}

std::string TripStatus::getReason() const {
    return reason;
}

Date TripStatus::getDelayTime() const {
    return delay_time;
}