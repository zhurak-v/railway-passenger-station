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

std::string Route::staticClass() {
    return "Route";
}
std::string Route::getClass() const { 
    return staticClass();
}