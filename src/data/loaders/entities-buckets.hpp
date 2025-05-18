#pragma once
#include <vector>
#include <memory>
#include "entities/entities.hpp"

struct EntitiesBuckets {
    std::vector<std::shared_ptr<Employee>> employees;
    std::vector<std::shared_ptr<Driver>> drivers;
    std::vector<std::shared_ptr<Locomotive>> locomotives;
    std::vector<std::shared_ptr<HeadDepartment>> head_departments;
    std::vector<std::shared_ptr<Department>> departments;
    std::vector<std::shared_ptr<Station>> stations;
    std::vector<std::shared_ptr<Route>> routes;
    std::vector<std::shared_ptr<Trip>> trips;
    std::vector<std::shared_ptr<Ticket>> tickets;
    std::vector<std::shared_ptr<Passenger>> passengers;
    std::vector<std::shared_ptr<Technician>> technicians;
    std::vector<std::shared_ptr<TechnicianBrigade>> technician_brigades;
    std::vector<std::shared_ptr<Train>> trains;
};