#include "data/loaders/split-entities.hpp"

EntitiesBuckets splitEntities(const std::vector<std::shared_ptr<Base>>& entities) {
    EntitiesBuckets buckets;

    for (const auto &entity : entities)
    {
        if (auto employee = std::dynamic_pointer_cast<Employee>(entity))
            buckets.employees.push_back(employee);
        
        if (auto driver = std::dynamic_pointer_cast<Driver>(entity))
            buckets.drivers.push_back(driver);

        if (auto locomotive = std::dynamic_pointer_cast<Locomotive>(entity))
            buckets.locomotives.push_back(locomotive);

        if (auto head_department = std::dynamic_pointer_cast<HeadDepartment>(entity))
            buckets.head_departments.push_back(head_department);

        if (auto department = std::dynamic_pointer_cast<Department>(entity))
            buckets.departments.push_back(department);

        if (auto station = std::dynamic_pointer_cast<Station>(entity))
            buckets.stations.push_back(station);

        if (auto route = std::dynamic_pointer_cast<Route>(entity))
            buckets.routes.push_back(route);

        if (auto trip = std::dynamic_pointer_cast<Trip>(entity))
            buckets.trips.push_back(trip);

        if (auto ticket = std::dynamic_pointer_cast<Ticket>(entity))
            buckets.tickets.push_back(ticket);

        if (auto technician = std::dynamic_pointer_cast<Technician>(entity))
            buckets.technicians.push_back(technician);

        if (auto technician_brigade = std::dynamic_pointer_cast<TechnicianBrigade>(entity))
            buckets.technician_brigades.push_back(technician_brigade);

        if (auto train = std::dynamic_pointer_cast<Train>(entity))
            buckets.trains.push_back(train);
    }

    return buckets;
};