#include <iostream>

#include "common/relation/relation.hpp"
#include "common/date/date.hpp"
#include "common/math/math.hpp"

#include "entities/entities.hpp"

#include "data/data.hpp"

#include <memory>

int main()
{

    auto station_a = std::make_shared<Station>("STN-31759", "A", std::vector<int> {0, 0});
    auto station_b = std::make_shared<Station>("STN-19753", "B", std::vector<int> {60, 0});
    auto station_c = std::make_shared<Station>("STN-34861", "C", std::vector<int> {120, 0});

    auto route = std::make_shared<Route>("RTE-57319", "A-C");

    ManyToMany<Route, Station> routes_to_stations;
    routes_to_stations.link(route, station_a);
    routes_to_stations.link(route, station_b);
    routes_to_stations.link(route, station_c);

    std::vector<std::vector<int>> positions;

    for (const auto& stations : routes_to_stations.getLinkedB(route))
    {
        positions.push_back(stations->getPosition());
    }

    route->setDistance(positions);
    std::cout << route->getDistance();
    

    return 0;
}