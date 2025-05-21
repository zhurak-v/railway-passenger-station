#include "services/relation/relation.hpp"
#include <iostream>

RelationServices::RelationServices(
    EmployeeService& employee_services,
    DriverRepository& driver_repository,
    LocomotiveRepository& locomotive_repository,
    TechnicianBrigadeRepository& technician_brigade_repository,
    StationRepository& station_repository,
    RouteRepository& route_repository,
    TripRepository& trip_repository

) : employee_services(employee_services),
    driver_repository(driver_repository),
    locomotive_repository(locomotive_repository),
    technician_brigade_repository(technician_brigade_repository),
    station_repository(station_repository),
    route_repository(route_repository),
    trip_repository(trip_repository)
{
    loadAllLinks(
        this->station_to_locomotives,
        station_repository.getAll(),
        locomotive_repository.getAll()
    );
    loadAllLinks(
        this->locomotive_to_drivers,
        locomotive_repository.getAll(),
        driver_repository.getAll()
    );
    loadAllLinks(
        this->technician_brigade_to_locomotives,
        technician_brigade_repository.getAll(),
        locomotive_repository.getAll()
    );
    loadAllLinks(
        this->routes_to_stations,
        route_repository.getAll(),
        station_repository.getAll()
    );
    loadAllLinks(
        this->route_to_trips,
        route_repository.getAll(),
        trip_repository.getAll()
    );
    loadAllLinks(
        this->locomotives_to_trips,
        locomotive_repository.getAll(),
        trip_repository.getAll()
    );
}

std::vector<std::shared_ptr<Station>> RelationServices::getStationsByRoute(const std::string& id) const {
    const auto route = route_repository.findById(id);
    return routes_to_stations.getLinkedB(route);
}

std::vector<std::shared_ptr<Route>> RelationServices::getRoutesByStation(const std::string& id) const {
    const auto station = station_repository.findById(id);
    return routes_to_stations.getLinkedA(station);
}

std::vector<std::shared_ptr<Trip>> RelationServices::getTripsByRoute(const std::string& id) const {
    const auto route = route_repository.findById(id);
    return route_to_trips.getLinkedB(route);
}

std::shared_ptr<Route> RelationServices::getRouteByTrip(const std::string& id) const {
    const auto trip = trip_repository.findById(id);
    return route_to_trips.getLinkedA(trip);
} 

std::vector<std::shared_ptr<Locomotive>> 
RelationServices::getLocomotivesAtStationInTime(
    const std::string& id,
    const Date& time
) const {
    auto station = station_repository.findById(id);
    auto routes = routes_to_stations.getLinkedA(station);

    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto& route : routes) {
        auto stations = routes_to_stations.getLinkedB(route);
        auto trips = route_to_trips.getLinkedB(route);

        for (const auto& trip : trips) {
            auto startTime = trip->getDepartureTime();
            auto startPos = stations.front()->getPosition();

            for (const auto& s : stations) {
                double dist = Math::getDistanceBetweenPointsKm(startPos, s->getPosition());
                double hours = dist / 60.0;
                Date arrival = startTime;
                arrival.addHours(hours);

                // if (s->getId() == id && Date::differenceInMinutes(arrival, time) == 0) {
                //     auto locomotives = locomotives_to_trips.getLinkedA(trip);
                //     // std::cout << arrival.serialize();
                //     result.insert(result.end(), locomotives.begin(), locomotives.end());
                //     break;
                // }

                 std::cout << s->getStationName() << " " << s->getPosition().getX() << std::endl;

                if (s->getId() == id) {
                    auto locomotives = locomotives_to_trips.getLinkedA(trip);
                    // std::cout << arrival.serialize();
                    result.insert(result.end(), locomotives.begin(), locomotives.end());
                    break;
                }
            }
        }
    }

    return result;
}