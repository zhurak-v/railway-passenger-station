#pragma once

#include "common/relation/relation.hpp"
#include "data/loaders/link-loader.hpp"

#include "services/base/employee-service.hpp"

#include "entities/driver.hpp"
#include "entities/locomotive.hpp"
#include "entities/brigade.hpp"
#include "entities/technician-brigade.hpp"

#include "entities/station.hpp"
#include "entities/route.hpp"
#include "entities/trip.hpp"

#include "data/repositories/driver-repository.hpp"
#include "data/repositories/locomotive-repository.hpp"
#include "data/repositories/station-repository.hpp"
#include "data/repositories/route-repository.hpp"
#include "data/repositories/trip-repository.hpp"
#include "data/repositories/technician-brigade-repository.hpp"

class RelationServices {
private:
    EmployeeService& employee_services;

    DriverRepository& driver_repository;
    LocomotiveRepository& locomotive_repository;
    TechnicianBrigadeRepository& technician_brigade_repository;
    StationRepository& station_repository;
    RouteRepository& route_repository;
    TripRepository& trip_repository;

private:
    OneToMany<Station, Locomotive> station_to_locomotives;
    OneToMany<Locomotive, Driver> locomotive_to_drivers;
    OneToMany<TechnicianBrigade, Locomotive> technician_brigade_to_locomotives;

private:
    ManyToMany<Route, Station> routes_to_stations;
    OneToMany<Route, Trip> route_to_trips;
    ManyToMany<Locomotive, Trip> locomotives_to_trips;

public:
    RelationServices(
        EmployeeService& employee_services,
        DriverRepository& driver_repository,
        LocomotiveRepository& locomotive_repository,
        TechnicianBrigadeRepository& technician_brigade_repository,
        StationRepository& station_repository,
        RouteRepository& route_repository,
        TripRepository& trip_repository
    );
    ~RelationServices() = default;

    std::vector<std::shared_ptr<Station>> getStationsByRoute(const std::string& id) const;
    std::vector<std::shared_ptr<Route>> getRoutesByStation(const std::string& id) const;

    std::vector<std::shared_ptr<Trip>> getTripsByRoute(const std::string& id) const;
    std::shared_ptr<Route> getRouteByTrip(const std::string& id) const;
    
    std::vector<std::shared_ptr<Locomotive>> getLocomotivesAtStationInTime(
        const std::string& id,
        const Date& time
    ) const;

}; 