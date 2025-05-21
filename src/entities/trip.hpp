#pragma once

#include <string>
#include <memory>
#include <vector>
#include "entities/base.hpp"
#include "entities/trip-status.hpp"
#include "common/date/date.hpp"

class Trip : public Base
{
private:
    const std::string trip_name;
    Date departure_time;
    const TripStatus status;
    const Date break_duration;

public:
    Trip(
        const std::string& id,
        const std::string& trip_name,
        const Date& departure_time,
        const Date& break_duration = Date(0, 15),
        const TripStatus& status = TripStatus()
    );
    ~Trip() = default;

public:
    std::string getTripName() const;
    Date getDepartureTime() const;

    Status getTripStatus() const;
    std::string getTripReason() const;
    Date getDelayTime() const;
    Date getBreakDuration() const;
    
public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Trip> deserialize(const std::string &data);
};
