#include "entities/route.hpp"

Route::Route(
    const std::string& id,
    const std::string& route_name
) : Base(id),
    route_name(route_name) {};

std::string Route::getRouteName() const {
    return route_name;
}

double Route::getDistance() const {
    return distance;
}

void Route::setDistance(const std::vector<std::vector<int>>& positions) {
    double calc_distance = 0;
    for (int i = 0; i < positions.size() - 1; ++i)
    {
        calc_distance += Math::getDistanceBetweenPointsKm(positions[i], positions[i + 1]);
    }
    distance = calc_distance;
}

std::string Route::staticClass() {
    return "Route";
}
std::string Route::getClass() const { 
    return staticClass();
}