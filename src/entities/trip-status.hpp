
#pragma once
#include <string>
#include "common/date/date.hpp"

enum class Status {
    Active,
    Delayed,
    Canceled
};

class TripStatus {
private:
    Status status;
    std::string reason;
    Date delay_time;

public:
    TripStatus();
    TripStatus(
        const Status& status, const std::string& reason, 
        const Date& delay_time = Date(0, 0));

    ~TripStatus() = default;

public:
    Status getStatus() const;
    std::string getReason() const;
    Date getDelayTime() const;
};