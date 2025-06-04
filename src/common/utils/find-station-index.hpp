#pragma once

#include <memory>
#include "entities/station.hpp"

int findStationIndex(
    const std::vector<std::shared_ptr<Station>>& stations, 
    const std::string& station_id
);