#include "entities/route.hpp"

Route::Route(
    const std::string& id,
    const std::string& route_name
) : Base(id),
    route_name(route_name) {};

std::string Route::getRouteName() const {
    return route_name;
}

Date Route::getDuration() const {
    return Math::getTravelTimeH(getDistance());
}

void Route::setDistance(const std::vector<Position>& positions) {
    double calc_distance = 0;
    for (int i = 0; i < positions.size() - 1; ++i)
    {
        const double dist = Math::getDistanceBetweenPointsKm(positions[i], positions[i + 1]);
        calc_distance += dist;
        distances.push_back(dist);
    }
    distance = calc_distance;
}

double Route::getDistance() const {
    return distance;
}

std::vector<double> Route::getDistances() const {
    return distances;
}

std::string Route::staticClass() {
    return "Route";
}
std::string Route::getClass() const { 
    return staticClass();
}