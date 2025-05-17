#include "entities/route.hpp"

Route::Route(
    const std::string& id,
    const std::string& route_name,
    const TypeRoute& type_route
) : Base(id),
    route_name(route_name), type_route(type_route) {};

std::string Route::getRouteName() const {
    return route_name;
}

TypeRoute Route::getTypeRoute() const {
    return type_route;
}

Date Route::getDuration() const {
    return Math::getTravelTimeH(getDistance());
}

void Route::setDistance(const std::vector<Position>& positions) {
    double calc_distance = 0;
    for (int i = 0; i < positions.size() - 1; ++i)
    {
        calc_distance += Math::getDistanceBetweenPointsKm(positions[i], positions[i + 1]);
    }
    distance = calc_distance;
}

double Route::getDistance() const {
    return distance;
}

std::string Route::staticClass() {
    return "Route";
}
std::string Route::getClass() const { 
    return staticClass();
}