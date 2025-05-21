#include "entities/route.hpp"
#include <iomanip>

std::string Route::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << std::quoted(getRouteName()) << " "
        << static_cast<int>(getTypeRoute());
    return oss.str();
}

std::shared_ptr<Route> Route::deserialize(const std::string &data)
{
    std::istringstream iss(data);

    std::string id;
    iss >> id;

    std::string route_name;
    iss >> std::quoted(route_name);
    
    int type_route_int;
    iss >> type_route_int;

    TypeRoute type_route = static_cast<TypeRoute>(type_route_int);

    return std::make_shared<Route>(id, route_name, type_route);
}
