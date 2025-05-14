#include "entities/route.hpp"


std::string Route::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << getRouteName();

    return oss.str();
}

std::shared_ptr<Route> Route::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string route_name;

    iss >> id >> route_name;

    return std::make_shared<Route>(id, route_name);
}