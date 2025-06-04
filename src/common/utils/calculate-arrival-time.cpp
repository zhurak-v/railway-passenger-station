#include "common/utils/calculate-arrival-time.hpp"

Date calculateArrivalTime(
    const Date& departure_time,
    const std::vector<std::shared_ptr<Station>>& stations,
    int start_index,
    const std::string& target_station_id,
    double speed,
    const Trip& trip)
{
    Date arrival_time = departure_time;
    for (int i = start_index + 1; i < stations.size(); ++i) {
        const auto& prev_station = stations[i - 1];
        const auto& current_station = stations[i];

        double dist = Math::getDistanceBetweenPointsKm(
            prev_station->getPosition(), current_station->getPosition()
        );

        double hours = dist / speed;
        arrival_time.addHours(hours);

        if (i != start_index + 1) {
            arrival_time.addMinutes(trip.getBreakDuration().getMinute());
        }

        if (current_station->getId() == target_station_id) {
            break;
        }
    }
    return arrival_time;
}