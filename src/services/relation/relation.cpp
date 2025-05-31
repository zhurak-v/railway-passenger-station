#include "services/relation/relation.hpp"
#include <iostream>

RelationServices::RelationServices(
    DriverRepository &driver_repository,
    LocomotiveRepository &locomotive_repository,
    TechnicianBrigadeRepository &technician_brigade_repository,
    StationRepository &station_repository,
    RouteRepository &route_repository,
    TripRepository &trip_repository,
    TrainRepository &train_repository

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
        locomotive_repository.getAll());
    loadAllLinks(
        this->locomotive_to_drivers,
        locomotive_repository.getAll(),
        driver_repository.getAll());
    loadAllLinks(
        this->technician_brigade_to_locomotives,
        technician_brigade_repository.getAll(),
        locomotive_repository.getAll());
    loadAllLinks(
        this->routes_to_stations,
        route_repository.getAll(),
        station_repository.getAll());
    loadAllLinks(
        this->route_to_trips,
        route_repository.getAll(),
        trip_repository.getAll());
    loadAllLinks(
        this->locomotives_to_trips,
        locomotive_repository.getAll(),
        trip_repository.getAll());
    loadAllLinks(
        this->train_to_locomotive,
        train_repository.getAll(),
        locomotive_repository.getAll());
}

std::vector<std::shared_ptr<Station>> RelationServices::getStationsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    return routes_to_stations.getLinkedB(route);
}

std::vector<std::shared_ptr<Route>> RelationServices::getRoutesByStation(const std::string &id) const
{
    const auto station = station_repository.findById(id);
    return routes_to_stations.getLinkedA(station);
}

std::vector<std::shared_ptr<Trip>> RelationServices::getTripsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    return route_to_trips.getLinkedB(route);
}

std::shared_ptr<Route> RelationServices::getRouteByTrip(const std::string &id) const
{
    const auto trip = trip_repository.findById(id);
    return route_to_trips.getLinkedA(trip);
}

std::vector<std::shared_ptr<Locomotive>>
RelationServices::getLocomotivesAtStationInTime(
    const std::string &id,
    const Date &time) const
{
    auto station = station_repository.findById(id);
    auto routes = routes_to_stations.getLinkedA(station);

    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &route : routes)
    {
        auto stations = routes_to_stations.getLinkedB(route);
        auto trips = route_to_trips.getLinkedB(route);

        for (const auto &trip : trips)
        {
            auto departure_time = trip->getDepartureTime();
            auto locomotives = locomotives_to_trips.getLinkedA(trip);

            for (const auto &loco : locomotives)
            {
                auto train = train_to_locomotive.getLinkedA(loco);
                if (!train) continue;

                double speed = static_cast<double>(train->getTrainType());
                Date arrival = departure_time;

                if (!stations.empty() && stations[0]->getId() == id)
                {
                    if (Date::differenceInMinutes(arrival, time) == 0)
                    {
                        result.push_back(loco);
                    }
                    continue;
                }

                auto prev_station = stations[0];
                for (size_t i = 1; i < stations.size(); ++i)
                {
                    const auto& current_station = stations[i];
                    double dist = Math::getDistanceBetweenPointsKm(
                        prev_station->getPosition(), current_station->getPosition()
                    );
                    double hours = dist / speed;
                    arrival.addHours(hours);

                    arrival.addMinutes(trip->getBreakDuration().getMinute());

                    if (current_station->getId() == id)
                    {
                        if (Date::differenceInMinutes(arrival, time) == 0)
                        {
                            result.push_back(loco);
                        }
                        break;
                    }

                    prev_station = current_station;
                }
            }
        }
    }

    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotivesByStation(
    const std::string &id) const
{
    auto station = station_repository.findById(id);
    return station_to_locomotives.getLinkedB(station);
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotivesByCompletedRoutest(
    const int completed_routest) const
{
    auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &locomotive : locomotives)
    {
        if (locomotive->getCompletedRoutes() == completed_routest)
            result.push_back(locomotive);
    }
    return result;
}

std::vector<std::pair<std::shared_ptr<Locomotive>, Date>>
RelationServices::getLocomotivesArrivalTimeAtStation(const std::string& station_id) const {
    auto station = station_repository.findById(station_id);
    auto routes = routes_to_stations.getLinkedA(station);

    std::vector<std::pair<std::shared_ptr<Locomotive>, Date>> result;

    for (const auto& route : routes) {
        auto stations = routes_to_stations.getLinkedB(route);
        auto trips = route_to_trips.getLinkedB(route);

        for (const auto& trip : trips) {
            auto departure_time = trip->getDepartureTime();
            auto locomotives = locomotives_to_trips.getLinkedA(trip);

            for (const auto& loco : locomotives) {
                auto train = train_to_locomotive.getLinkedA(loco);
                if (!train) continue;

                double speed = static_cast<double>(train->getTrainType());
                Date arrival_time = departure_time;

                if (!stations.empty() && stations[0]->getId() == station_id) {
                    result.emplace_back(loco, arrival_time);
                    continue;
                }

                auto prev_station = stations[0];
                for (size_t i = 1; i < stations.size(); ++i) {
                    const auto& current_station = stations[i];
                    double dist = Math::getDistanceBetweenPointsKm(
                        prev_station->getPosition(), current_station->getPosition()
                    );
                    double hours = dist / speed;
                    arrival_time.addHours(hours);

                    arrival_time.addMinutes(trip->getBreakDuration().getMinute());

                    if (current_station->getId() == station_id) {
                        result.emplace_back(loco, arrival_time);
                        break;
                    }

                    prev_station = current_station;
                }
            }
        }
    }

    return result;
}
