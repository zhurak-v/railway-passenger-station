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
    std::string trip_name;
    Date departure_time;
    TripStatus status;

public:
    Trip(
        const std::string& id,
        const std::string& trip_name,
        const Date& departure_time
    );
    Trip(
        const std::string& id,
        const std::string& trip_name,
        const Date& departure_time,
        const TripStatus& status
    );
    ~Trip() = default;

public:
    std::string getTripName() const;
    Date getDepartureTime() const;

    Status getTripStatus() const;
    std::string getTripReason() const;
    Date getDelayTime() const;
    
public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Trip> deserialize(const std::string &data);
};
