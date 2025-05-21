#include "services/relation/relation.hpp"
#include <iostream>

RelationServices::RelationServices(
    DriverRepository& driver_repository,
    LocomotiveRepository& locomotive_repository,
    TechnicianBrigadeRepository& technician_brigade_repository,
    StationRepository& station_repository,
    RouteRepository& route_repository,
    TripRepository& trip_repository,
    TrainRepository& train_repository

) : driver_repository(driver_repository),
    locomotive_repository(locomotive_repository),
    technician_brigade_repository(technician_brigade_repository),
    station_repository(station_repository),
    route_repository(route_repository),
    trip_repository(trip_repository),
    train_repository(train_repository)
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
    loadAllLinks(
        this->train_to_locomotive,
        train_repository.getAll(),
        locomotive_repository.getAll()
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
            auto departure_time = trip->getDepartureTime();

            // std::cout << departure_time.serialize() << std::endl;

            auto start_pos = stations[0]->getPosition();

            for (const auto& s : stations) {
                double dist = Math::getDistanceBetweenPointsKm(start_pos, s->getPosition());
                auto locomotives = locomotives_to_trips.getLinkedA(trip);

                for (const auto& loco : locomotives) {
                    auto train = train_to_locomotive.getLinkedA(loco);

                    double speed = static_cast<double>(train->getTrainType());
                    double hours = dist / speed;

                    Date arrival = departure_time;
                    arrival.addHours(hours);

                    std::cout << arrival.serialize() << std::endl;

                    if (s->getId() == id && Date::differenceInMinutes(arrival, time) == 0) {
                        result.push_back(loco);
                        break;
                    }
                }
            }
        }
    }

    return result;
}