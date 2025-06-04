#pragma once

#include <memory>
#include "common/date/date.hpp"
#include "common/math/math.hpp"
#include "entities/station.hpp"
#include "entities/trip.hpp"

Date calculateArrivalTime
(
    const Date& departure_time,
    const std::vector<std::shared_ptr<Station>>& stations,
    int start_index,
    const std::string& target_station_id,
    double speed,
    const Trip& trip
);